#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B;
int main() {
    cin >> A >> B;

    string s[105];

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i < 50) {
                s[i].push_back('.');
            } else {
                s[i].push_back('#');
            }
        }
    }

    // 上半分 . -> # に変更する B を増やす (B - 1回)
    int cnt = 0;
    for (int i = 0; i < 50; i += 2) {

        if (B - 1 == cnt) break;

        for (int j = 0; j < 100; j += 2) {
            if (B - 1 == cnt) break;
            s[i][j] = '#';

            cnt++;
        }
    }

    // 下半分 # -> . に変更する A を増やす (A - 1回)
    cnt = 0;
    for (int i = 51; i < 100; i += 2) {

        if (A - 1 == cnt) break;

        for (int j = 0; j < 100; j += 2) {
            if (A - 1 == cnt) break;
            s[i][j] = '.';
            cnt++;
        }
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100) {
        cout << s[i] << endl;
    }

}