#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<char, vector<ll>> m;
    for (char i = 'a'; i <= 'z'; ++i) {
        m[i] = vector<ll>();
    }
    for (ll i = 0; i < n; ++i) {
        m[s[i]].emplace_back(i);
    }

    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        ll cur = 0;
        for (auto & p : m) {
            bool hasSmaller = false;
            bool hasLarger = false;
            for (auto j : p.second) {
                if (j <= i) {
                    hasSmaller = true;
                } else if (j > i) {
                    hasLarger = true;
                    break;
                }
            }
            if (hasSmaller && hasLarger) {
                ++cur;
            }
        }
        cerr << i << ":" << cur << endl;
        res = max(res, cur);
    }
    cout << res << endl;

}
