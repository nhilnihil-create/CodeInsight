
  #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define wuyt main
typedef long long ll;
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > >
template<class T> inline T min(T &x,const T &y){return x>y?y:x;}
template<class T> inline T max(T &x,const T &y){return x<y?y:x;}
//#define getchar()(p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[(1 << 21) + 1], *p1 = buf, *p2 = buf;
ll read(){ll c = getchar(),Nig = 1,x = 0;while(!isdigit(c) && c!='-')c = getchar();
if(c == '-')Nig = -1,c = getchar();
while(isdigit(c))x = ((x<<1) + (x<<3)) + (c^'0'),c = getchar();
return Nig*x;}
#define read read()
const ll inf = 1e15;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
#define start int wuyt()
#define end return 0
start{
    ll n=read,k=read;
    ll t = n / k, t1 = (n + k / 2) / k;
    ll ans = t * t * t;
    if (k % 2 == 0) ans += t1 * t1 * t1;
    cout<<ans;
	end;
}
