#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s; cin >> s;

    vector<bool> used(26, false);
    vector<string> v;
    rep(i, s.size()) {
        used[s[i] - 'a'] = true;

        rep(j, 26) {
            if (s[i] - 'a' >= j) continue;
            if (used[j]) continue;
            v.push_back(s.substr(0, i) + (char)('a' + j));
            break;
        }
    }
    rep(j, 26) {
        if (!used[j]) {
            v.push_back(s + (char)('a' + j));
            break;
        }
    }
    if (v.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(all(v));
    cout << v[0] << endl;
}
