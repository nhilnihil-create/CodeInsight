#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vi> a(h, vi(w, 0));
    rep(i, h) rep(j, w) cin >> a[i][j];

    vector<vector<bool>> b(h, vector<bool>(w, false));

    vector<vector<int>> v(h * w, vector<int>(4, -1));

    int cnt = 0;
    for (int i = 0; i < h; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; j++) {
                if (a[i][j] % 2 == 1) {
                    if (j == w - 1) {
                        if (i != h - 1) {
                            v[cnt][0] = i + 1;
                            v[cnt][1] = j + 1;
                            v[cnt][2] = i + 1 + 1;
                            v[cnt][3] = j + 1;
                            cnt++;

                            a[i][j]--;
                            a[i + 1][j]++;
                        }
                    } else {
                        v[cnt][0] = i + 1;
                        v[cnt][1] = j + 1;
                        v[cnt][2] = i + 1;
                        v[cnt][3] = j + 1 + 1;
                        cnt++;

                        a[i][j]--;
                        a[i][j + 1]++;
                    }
                }
            }
        } else {
            for (int j = w - 1; j >= 0; j--) {
                if (a[i][j] % 2 == 1) {
                    if (j == 0) {
                        if (i != h - 1) {
                            v[cnt][0] = i + 1;
                            v[cnt][1] = j + 1;
                            v[cnt][2] = i + 1 + 1;
                            v[cnt][3] = j + 1;
                            cnt++;

                            a[i][j]--;
                            a[i + 1][j]++;
                        }
                    } else {
                        v[cnt][0] = i + 1;
                        v[cnt][1] = j + 1;
                        v[cnt][2] = i + 1;
                        v[cnt][3] = j -1 + 1;
                        cnt++;

                        a[i][j]--;
                        a[i][j - 1]++;
                    }
                }
            }
        }
    }

    cout << cnt << endl;
    rep(i, cnt) {
        cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << " " << v[i][3] << endl;
    }
    //cout << endl;
}