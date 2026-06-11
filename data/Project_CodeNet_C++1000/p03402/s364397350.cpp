#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__

int main() {
    int A, B;
    cin >> A >> B;

    vector<vector<char>> G(100, vector<char>(100));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (j <= 49) {
                G[i][j] = '.';
            } else {
                G[i][j] = '#';
            }
        }
    }

    // A-1個塗る
    int cnt = 0;
    bool finish = false;
    for (int i = 0; i < 100; i += 2) {
        for (int j = 51; j < 100; j += 2) {
            if (cnt >= A - 1) {
                finish = true;
                break;
            };
            G[i][j] = '.';
            cnt++;
        }
        if (finish) break;
    }

    // B-1個塗る
    cnt = 0;
    finish = false;
    for (int i = 0; i < 100; i += 2) {
        for (int j = 0; j < 50; j += 2) {
            if (cnt >= B - 1) {
                finish = true;
                break;
            };
            G[i][j] = '#';
            cnt++;
        }
        if (finish) break;
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100) {
        rep(j, 100) {
            cout << G[i][j];
        }
        cout << endl;
    }
}