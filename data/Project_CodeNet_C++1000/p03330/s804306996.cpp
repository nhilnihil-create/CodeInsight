#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c;  cin >> n >> c;
    vector<vector<long long> > d(c, vector<long long>(c)), s(n, vector<long long>(n));
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++)
            cin >> d[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<vector<long long> > cnt(3, vector<long long>(c, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt[(i+j) % 3][s[i][j]]++;
        }
    }

    long long ans = 1e18, tmp;
    for (int k = 0; k < c; k++) {
        for (int l = 0; l < c; l++) {
            for (int m = 0; m < c; m++) {
                if (k == l || l == m || m == k)
                    continue;
                tmp = 0;
                for (int i = 0; i < c; i++) {
                    if (i != k)
                        tmp += cnt[0][i] * d[i][k];
                    if (i != l)
                        tmp += cnt[1][i] * d[i][l];
                    if (i != m)
                        tmp += cnt[2][i] * d[i][m];
                }

                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}