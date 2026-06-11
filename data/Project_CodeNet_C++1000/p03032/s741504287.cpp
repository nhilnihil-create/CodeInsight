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
    vector<ll> v;
    rep(i, N) {
        ll num; cin >> num;
        v.push_back(num);
    }

    ll maxn = -inf;
    for (ll x = 0; x <= min(N, K); x++) {
        // x: sum of a and b;
        priority_queue<ll, vector<ll>, greater<ll>> pque;
        for (ll a = 0; a <= x; a++) {
            deque<ll> que(v.begin(), v.end());
            ll b = x - a;
            rep(i, a) {
                ll num = que.front(); que.pop_front();
                pque.push(num);
            }

            rep(i, b) {
                ll num = que.back(); que.pop_back();
                pque.push(num);
            }

            rep(i, K - x) {
                if (pque.size() && pque.top() <= 0) pque.pop();
            }

            ll total = 0;
            while (pque.size()) {
                total += pque.top(); pque.pop();
            }
            maxn = max(maxn, total);
        }
    }
    cout << maxn << endl;
    return 0;
}