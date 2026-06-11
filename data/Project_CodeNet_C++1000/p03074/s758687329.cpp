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
    string S; cin >> S;

    ll i = 0;
    vector<pair<ll, ll>> v; // {{count_1, count_0}}
    while (i < S.size()) {
        ll count_1 = 0;
        while (i < S.size() && S[i] == '1') i++, count_1++;
        if (i == S.size()) {
            v.push_back({count_1, 0});
            break;
        }
        ll count_0 = 0;
        while (i < S.size() && S[i] == '0') i++, count_0++;
        v.push_back({count_1, count_0});
    }
    // for (auto elem : v) {
    //     cout << elem.first << " " << elem.second << endl;
    // }

    v.push_back({0, 0});

    if (v.size()-1 <= K) {
        ll total = 0;
        for (auto elem : v) {
            total += elem.first + elem.second;
        }
        cout << total << endl;
        return 0;
    }

    ll max_num = 0;
    ll total = 0;
    rep(i, K - 1) {
        total += v[i].first + v[i].second;
    }
    //cout << "total: " << total << endl;

    reprr(i, K - 1, v.size()-1) {
        total += v[i].first + v[i].second;
        total += v[i+1].first;
        //cout << "total(before): " << total << " ";
        max_num = max(max_num, total);
        total -= v[i+1].first;
        total -= (v[i - K + 1].first + v[i - K + 1].second);
        //cout << "total(after): " << total << endl;
    }
    cout << max_num << endl;
    return 0;
}