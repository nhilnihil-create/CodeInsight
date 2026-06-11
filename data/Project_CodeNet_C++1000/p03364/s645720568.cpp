#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        S[i] += S[i];
    }
    for (int i = N; i < 2 * N; i++) {
        S[i] = S[i - N];
    }

    int ans = 0;
    for (int a = 0; a < N; a++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (S[i + a][j] != S[j + a][i]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans * N << endl;
}
