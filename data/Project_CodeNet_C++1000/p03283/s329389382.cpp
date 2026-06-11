#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int, int> pint;
#define mp make_pair

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    multiset<pint> st;
    for (int k = 0; k < m; ++k) {
        int x, y;
        cin >> x >> y;
        st.insert(mp(x, y));
    }
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1] + st.count(mp(i, j));
        }
    }
    
    for (int l = 0; l < q; ++l) {
        int a, b;
        cin >> a >> b;
        cout << v[b][b] - v[a - 1][b] - v[b][a - 1] + v[a - 1][a - 1] << endl;
    }
}
