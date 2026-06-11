#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);

    int max_a = -INF;
    int max_idx;
    int min_a = INF;
    int min_idx;
    rep(i, n) {
        cin >> a[i];
        if (a[i] > max_a) {
            max_idx = i;
            max_a = a[i];
        }
        if (a[i] < min_a) {
            min_idx = i;
            min_a = a[i];
        }
    }

    if (abs(max_a) >= abs(min_a)) {
        cout << 2 * (n - 1) << endl; 
        rep(i, n) {
            if (i == max_idx) continue;
            cout << max_idx + 1 << " " << i + 1 << endl;
        }
        REP(i, 1, n) {
            cout << i << " " << i + 1 << endl;
        }
    } else {
        cout << 2 * (n - 1) << endl; 
        rep(i, n) {
            if (i == min_idx) continue;
            cout << min_idx + 1 << " " << i + 1 << endl;
        }
        for (int i = n; i > 1; i--) {
            cout << i << " " << i - 1 << endl;
        }
    }

    return 0;
}