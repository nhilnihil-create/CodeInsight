#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    set<ll> sa;
    rep(i, n) {
        cin >> a[i];
        sa.insert(a[i]);
    }
    ll ans = LONG_LONG_MAX;
    for(auto &x : sa) {
        vector<ll> tmp;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        rep(i, n) {
            if (a[i] < x) {
                sort(all(tmp));
                rep(j, sz(tmp) - k + 1) {
                    pq.push(tmp[j]);
                }
                tmp.clear();
            }
            else {
                tmp.push_back(a[i]);
            }
        }
        {
            sort(all(tmp));
            rep(j, sz(tmp) - k + 1) {
                pq.push(tmp[j]);
            }
            tmp.clear();
        }
        if (sz(pq) < q) continue;
        rep(j, q - 1) pq.pop();
        ans = min(ans, pq.top() - x);
    }
    cout << ans << endl;
    return 0;
}
