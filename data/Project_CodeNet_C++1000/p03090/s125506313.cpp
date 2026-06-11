#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;

signed main() {
    int n;
    cin >> n;
    // 実験より
    // 奇数の時s=2+3+...+n-1
    // 偶数の時s=1+2+...+n-1
    vector<pint> vec;
    int s;
    bool chk[n][n];
    rep (i, 0, n) rep (j, 0, n) chk[i][j] = 1;
    set<pint> st;
    if (n % 2 == 1) {
        s = (n - 1 + 2) * (n - 2) / 2;
        rep (i, 0, n) {
            rep (j, 0, n) {
                if (i == j) continue;
                if (i + j != n - 2)
                    st.insert ({min (i + 1, j + 1), max (i + 1, j + 1)});
            }
        }
    } else {
        s = (1 + n - 1) * (n - 1) / 2;
        rep (i, 0, n) {
            rep (j, 0, n) {
                if (i == j) continue;
                if (i + j != n - 1)
                    st.insert ({min (i + 1, j + 1), max (i + 1, j + 1)});
            }
        }
    }
    int m = st.size();
    cout << m << "\n";
    for (auto p : st) {
        cout << p.first << " " << p.second << "\n";
    }
}