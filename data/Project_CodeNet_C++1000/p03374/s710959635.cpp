#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 5;

pair<ll, ll> p[maxn];
int N;
ll C;
ll g[maxn], f[maxn];

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> N >> C;
    for (int i=1; i<=N; ++i){
        cin >> p[i].fi >> p[i].se;
    }
    p[N+1].fi = C;
    ll res = 0, now = 0, dist = 0;
    for (int i=1; i<=N; ++i){
        dist -= p[i].fi - p[i-1].fi;
        now += p[i].se;
        f[i] = max(f[i-1], now + dist);
    }
    now = 0, dist = 0;
    for (int i=N; i>=1; --i){
        dist -= p[i+1].fi - p[i].fi;
        now += p[i].se;
        g[i] = max(g[i+1], now + dist);
        res = max(res, now + dist);
        res = max(res, f[i-1] + now + dist * 2);
    }
    now = 0, dist = 0;
    for (int i=1; i<=N; ++i){
        dist -= p[i].fi - p[i-1].fi;
        now += p[i].se;
        res = max(res, now + dist);
        res = max(res, g[i+1] + now + dist * 2);
    }
    cout << res << '\n';
}
