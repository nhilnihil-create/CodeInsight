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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> ab(m);
    rep(i, m) cin >> ab[i].first >> ab[i].second;
    sort(all(ab), [](const pair<ll, ll> &a, const pair<ll, ll> &b){ return a.second < b.second; });
    ll end = -1, ans = 0;
    rep(i, m) {
        if (ab[i].first >= end) {
            end = ab[i].second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
