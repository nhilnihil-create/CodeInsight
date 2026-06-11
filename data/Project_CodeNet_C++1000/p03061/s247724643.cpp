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
map<ll, ll> dp;
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
int vis[N][N];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
// void dfs(int x, int y)
// {
//     cout << x << ' ' << y << endl;
//     vis[x][y] = 1;
//     for (int i = 0; i < 4; i++)
//     {
//         int xx = x + dir[i][0], yy = y + dir[i][1];
//         if (xx <= 0)
//             xx = n;
//         if (yy <= 0)
//             yy = m;
//         if (xx > n)
//             xx = 1;
//         if (yy > m)
//             yy = 1;
//         if (!vis[xx][yy])
//             dfs(xx, yy);
//     }
// }
//int n, m;
// bool check(int x)
// {
//     bool fla;
//     for (int i = 1; i <= n; i++)
//     {
//         fla = false;
//         for (int j = 1; j <= m; j++)
//         {
//             if (((a[i] & b[j]) | x) == x)
//             {
//                 fla = true;
//                 break;
//             }
//         }
//         if (!fla)
//             return false;
//     }
//     return true;
// }
//int dp[maxn], dx[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, ans = 1, x, res;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], dp[a[i]]++;
    sort(a + 1, a + 1 + n);
    for (ll i = 1; i <= n; i++)
    {
        int fla = 0, res;
        for (ll j = 1; j <= n; j += dp[a[j]])
        {
            if (i == j && dp[a[i]] == 1)
                continue;
            if (!fla)
                fla = 1, res = a[j];
            res = gcd(res, a[j]);
           // cout << j << endl;
            if (res == 1)
                break;
        }
        //cout << "****" << endl;
        ans = max(ans, res);
    }
    cout << ans << endl;
}
