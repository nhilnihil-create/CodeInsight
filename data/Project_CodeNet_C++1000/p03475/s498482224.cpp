#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> C(N-1), S(N-1), F(N-1);
    REP(i, N-1) cin >> C[i] >> S[i] >> F[i];
    REP(i, N) {
        int t = 0;
        for (int j = i; j < N - 1; j++) {
            if (t < S[j]) t = S[j];
            else t = (t + F[j] - 1) / F[j] * F[j];
            t += C[j];
        }
        cout << t << endl;
    }
}