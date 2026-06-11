#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        auto nothing = [&](int i, int j) -> bool {
                return i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '.';
        };

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        if (grid[i][j] == '.') continue;
                        if (nothing(i - 1, j) && nothing(i + 1, j) && nothing(i, j - 1) && nothing(i, j + 1)) {
                                cout << "No";
                                return;
                        }
                }
        }

        cout << "Yes";
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
