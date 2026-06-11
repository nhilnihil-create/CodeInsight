#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;
    vector<string> S(N); rep(i, N) cin >> S[i];

    int cnt = 0, x = 0, y = 0, z = 0;
    rep(i, N) {
        int first = 0;
        int last = S[i].size() - 1;
        rep(j, S[i].size() - 1) {
            if ((S[i][j] == 'A') && (S[i][j + 1] == 'B')) {
                cnt++;
            }
        }

        if ((S[i][first] == 'B') && (S[i][last] == 'A')) {
            z++;
        } else if (S[i][first] == 'B') {
            y++;
        } else if (S[i][last] == 'A') {
            x++;
        }
    }

    // 末尾がA, 先頭がB
    if (z > 0) {
        // 末尾がA, 先頭がBの一つの大きい文字列を作る
        cnt += (z - 1);

        // 先頭にくっつける
        if (x > 0) {
            cnt++;
            x--;
        }

        // 末尾にくっつける
        if (y > 0) {
            cnt++;
            y--;
        }
    }

    cnt += min(x, y);

    cout << cnt << endl;
}
