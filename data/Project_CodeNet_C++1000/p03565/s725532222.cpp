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
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    if (n < m) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for (int i = n-m; i >= 0; i--) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (s[i+j] != '?' && s[i+j] != t[j]) {
                match = false;
                continue;
            }
        }

        if (match) {
            for (int j = 0; j < m; j++) {
                if (s[i+j] == '?') s[i+j] = t[j];
            }
            rep(k, n) {
                if (s[k] == '?') s[k] = 'a';
            }
            cout << s << endl;
            return 0;
        }
    }

    cout << "UNRESTORABLE" << endl;
}
