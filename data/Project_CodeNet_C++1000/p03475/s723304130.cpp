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

    rep(i, n - 1) {
        int ans = 0;
        ans += S[i] + C[i];

        for (int j = i + 1; j < n - 1; j++) {
            if (ans == S[j]) {
                ans += C[j];
            } else if (ans < S[j]) {
                ans += C[j] + (S[j] - ans);
            } else {
                if ((ans - S[j]) % F[j] == 0) {
                    ans += C[j];
                } else {
                    ans += C[j] + F[j] - (ans - S[j]) % F[j];
                }
            }
        }

        cout << ans << endl;
    }

    cout << 0 << endl;
}