#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n, m, Q;    cin >> n >> m >> Q;
    vector<vector<int> > a(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < m; i++) {
        int l, r;   cin >> l >> r;
        a[l][r]++;
    }
    vector<int> p(Q), q(Q);
    for (int i = 0; i < Q; i++)
        cin >> p[i] >> q[i];

    vector<vector<int> > sum(n+2, vector<int>(n+2, 0));
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n+1; j++) {
            sum[i+1][j+1] = a[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << sum[q[i]+1][q[i]+1] - sum[p[i]][q[i]+1] - sum[q[i]+1][p[i]] + sum[p[i]][p[i]] << endl;
    }
    return 0;
}