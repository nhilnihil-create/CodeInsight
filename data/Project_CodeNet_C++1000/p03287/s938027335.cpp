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
template<class T> inline T min(T& x, const T& y) { return x > y ? y : x; }
template<class T> inline T max(T& x, const T& y) { return x < y ? y : x; }
//#define getchar()(p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[(1 << 21) + 1], *p1 = buf, *p2 = buf;
ll read() {
    ll c = getchar(), Nig = 1, x = 0; while (!isdigit(c) && c != '-')c = getchar();
    if (c == '-')Nig = -1, c = getchar();
    while (isdigit(c))x = ((x << 1) + (x << 3)) + (c ^ '0'), c = getchar();
    return Nig * x;
}
#define read read()
const ll inf = 1e15;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
#define start int wuyt()
#define end return 0
#define N 1005
///int num[maxn];
///int sum[maxn];
map<ll, ll>mp;
int n;
ll m;
start{
    n = read,m = read;
    ll num,sum = 0,ans = 0;
        mp.clear();
        mp[0]++;
        for (int i = 1; i <= n; i++) {
            num = read;
            sum += num;
            sum %= m;
            ans += mp[sum];
            mp[sum]++;
        }
        printf("%lld\n",ans);
    end;
}