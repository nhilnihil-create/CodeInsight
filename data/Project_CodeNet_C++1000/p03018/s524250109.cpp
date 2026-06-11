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

    ll ans = 0, A = 0;
    int n = s.size();
    rep(i, n) {
        if (s[i] == 'A') A++;
        else if (i < n-1 && s[i] == 'B' && s[i+1] == 'C') continue;
        else if (i > 0 && s[i-1] == 'B' && s[i] == 'C') ans += A;
        else A = 0;
    }
    cout << ans << endl;
}
