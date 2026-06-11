#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;

// input
int N;
vector<int> C, S, F;


void input() {
    cin >> N;
    C = S = F = vector<int>(N - 1);
    rep(i, N - 1) cin >> C[i] >> S[i] >> F[i];
}


int main() {
    input();
    rep(i, N) {
        int ans = 0;
        for (int j = i; j < N - 1; j++) {
            if (ans <= S[j]) {
                ans = S[j] + C[j];
            } else {
                int x = (ans - 1) / F[j] + 1;
                ans = x * F[j] + C[j];
            }
        }
        cout << ans << endl;
    }
}
