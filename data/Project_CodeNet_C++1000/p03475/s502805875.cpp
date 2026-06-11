#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> C(n - 1), S(n - 1), F(n - 1);
    rep(i, n - 1) {
        cin >> C[i] >> S[i] >> F[i];
    }

    for (int i = 0; i < n - 1; i++) {
        // これでi+1に移動
        int res = S[i] + C[i];
        for (int j = i + 1; j < n - 1; j++) {
            if (res == S[j]) {
                res += 0;
            } else if (res > S[j]) {

                if ((res/ F[j]) * F[j] == res) {
                    res += 0;
                } else {
                    res += ((res/ F[j]) + 1) * F[j] - res;
                }
            } else {
                res += S[j] - res;
            }
            res += C[j];
        }

        cout << res << endl;
    }

    cout << 0 << endl;
}