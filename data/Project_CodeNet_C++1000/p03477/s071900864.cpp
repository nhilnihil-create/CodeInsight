#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i = 0;i < n; i++)
#define REP(i,n) for(int i = 1;i <= n; i++)
// ----GCC ONLY---- //
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// ----        ---- //
#define ll long long
#define PB push_back
#define MOD 10000007
#define PI 3.14159265359

using namespace std;

int main(){

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int Right = c+d;
    int Left = a+b;

    if(Right > Left)puts("Right");
    else if(Right < Left)puts("Left");
    else puts("Balanced");

}

