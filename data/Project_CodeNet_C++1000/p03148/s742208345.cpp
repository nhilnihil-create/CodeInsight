#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    priority_queue<pair<ll, ll>> pq;
    for(int i = 0; i < N; i++) {
        ll t, d;
        cin >> t >> d;
        pq.push({d, t - 1});
    }
    ll ans = 0;
    ll cnt[N] = {0};
    ll kinds = 0;
    priority_queue<ll> Q;
    for(int i = 0; i < K; i++) {
        auto dt = pq.top();
        pq.pop();
        cnt[dt.second]++;
        if(cnt[dt.second] > 1)
            Q.push(-dt.first);
        else
            kinds++;
        ans += dt.first;
    }
    ans += kinds * kinds;
    // debug(ans);
    ll a = ans;
    while(!pq.empty() && !Q.empty()) {
        auto dt = pq.top();
        pq.pop();
        if(cnt[dt.second] > 0)
            continue;
        cnt[dt.second]++;
        kinds++;
        a += dt.first + 2 * kinds - 1 + Q.top();
        Q.pop();
        ans = max(ans, a);
    }
    cout << ans << endl;
    return 0;
}
