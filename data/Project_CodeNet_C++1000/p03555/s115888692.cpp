#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const int MOD = 1e9+7;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {
        cout << "NO" << endl;
        return 0;
    }

    bool ok = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[t.length() - 1 - i]) ok = false;
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}