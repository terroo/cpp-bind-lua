#include <iostream>

extern "C" {
  #include <lua5.1/lua.h>
  #include <lua5.1/lauxlib.h>

  int helloworld(lua_State *L){
    lua_pushstring(L, "Hello, World!");
    return 1;
  }

  int echo(lua_State *L){
    std::cout << "Here, you don't even need a print in Lua\n";
    return 1;
  }

  int show(lua_State *L){
    std::cout << luaL_checklstring(L, 1, NULL) << '\n';
    return 1;
  }

  int add(lua_State *L){
    double a = luaL_checknumber(L, 1);
    double b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a + b);
    return 1;
  }

  static const struct luaL_Reg functions [] = {
    {"helloworld", helloworld},
    {"echo", echo},
    {"show", show},
    {"add", add},
    {NULL, NULL}
  };

  int luaopen_terroo(lua_State *L){
    luaL_register(L, "terroo", functions);
    return 1;
  }
}

