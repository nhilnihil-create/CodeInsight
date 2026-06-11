#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll N, K; cin >> N >> K;
    vll V(N); rep(i, N) cin >> V[i];

    ll maxn = -inf;
    for (ll x = 0; x <= min(N, K); x++) {
        // x: sum of a + b
        for (ll a = 0; a <= x; a++) {
            ll b = x - a;
            deque<ll> que(V.begin(), V.end());
            priority_queue<ll, vector<ll>, greater<ll>> pque;
            rep(i, a) pque.push(que.front()), que.pop_front();
            rep(i, b) pque.push(que.back()), que.pop_back();
            rep(i, K - x) if (pque.size() && pque.top() < 0) pque.pop();
            ll total = 0;
            while (pque.size()) total += pque.top(), pque.pop();
            maxn = max(maxn, total);
        }
    }
    cout << maxn << endl;
    return 0;
}