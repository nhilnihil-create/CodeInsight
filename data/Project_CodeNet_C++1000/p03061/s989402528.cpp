#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <math.h>
using namespace std;
typedef long long ll;
//#define ll long long
const ll N = 2009;
const ll maxn = 1e5 + 20;
const ll mod = 1000000007;
//ll inv[maxn], vis[maxn], dis[maxn], head[maxn];
ll fac[maxn], a[maxn], q[maxn], b[maxn], c[maxn], pre[maxn];
vector<ll> vec;
//typedef pair<ll, ll> p;
//priority_queue<p, vector<p>, greater<p> > m;
ll sum[maxn];
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
map<ll, ll> mp;
ll ksm(ll a, ll b)
{
    a %= mod;
    ll ans = 1ll;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return ans;
}
ll lowbit(ll x)
{
    return x & (-x);
}
int dp[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, ans = 1, x, res;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]]++;
    sort(a + 1, a + 1 + n);
    for (ll i = 1; i <= n; i++)
    {
        int fla = 0, res;
        for (ll j = 1; j <= n; j += mp[a[j]])
        {
            if (i == j && mp[a[i]] == 1)
                continue;
            if (!fla)
                fla = 1, res = a[j];
            res = gcd(res, a[j]);
            if (res == 1)
                break;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}
