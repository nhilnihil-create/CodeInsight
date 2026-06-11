// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int k[12];
int s[12][12];
int p[12];

int main() {
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        cin >> k[i];
        rep(j, k[i]) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    rep(i, M) {
        cin >> p[i];
    }

    int res = 0;
    rep(div, 1<<N) {
        // cout << "here?" << endl;
        bool b = true;
        rep(i, M) {
            int sm = 0;
            rep(j, k[i]) {
                if (div>>s[i][j]&1) sm++;
            }
            if (sm%2!=p[i]) {
                b = false;
                break;
            }
        }
        if (b) res++;
    }

    cout << res << endl;
    return 0;
}