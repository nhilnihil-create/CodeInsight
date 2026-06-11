#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N;
    cin >> N;

    vector<int> x(N), y(N), h(N);
    int se = 0;
    rep(i, N) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] != 0)
            se = i;
    }

    rep(i, 101) {
        rep(j, 101) {
            bool flag = true;
            int top = abs(x[se] - i) + abs(y[se] - j) + h[se];
            rep(k, N) {
                if (h[k] == 0) {
                    if (top - abs(x[k] - i) - abs(y[k] - j) > 0) {
                        flag = false;
                        break;
                    }
                } else if (top != abs(x[k] - i) + abs(y[k] - j) + h[k]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << i << " " << j << " " << top << endl;
                return 0;
            }
        }
    }

    return 0;
}