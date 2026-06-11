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

    int n;
    cin >> n;
    vector<string> s(n);

    int ans = 0;
    int a = 0, b = 0, ab = 0;
    rep(i, n) {
        cin >> s[i];
        int t = s[i].length();
        rep(j, t - 1) {
            if (s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
        }

        if (s[i][0] == 'B' && s[i][t-1] == 'A') ab++;
        else{
            if (s[i][0] == 'B') b++;
            if (s[i][t-1] == 'A') a++;
        }
    }

    if (ab > 0) {
        ans += ab - 1;
        if (a > 0) {
            ans++;
            a--;
        }
        if (b > 0) {
            ans++;
            b--;
        }
    }

    ans += min(a, b);

    cout << ans << endl;

    return 0;
}