#include <bits/stdc++.h>
using namespace std;

long ans;
long M, N, K;
long X, Y;
vector<long> A, B, C;
vector<long> P;
vector<vector<long>> S;

int main(void) {

    cin >> N >> M;
    S.resize(M);
    P.resize(M);

    for (long i = 0; i < M; i++) {
        long k; cin >> k; S[i].resize(k);
        for (long j = 0; j < k; j++) {
            cin >> S[i][j];
            S[i][j]--;
        }
    }

    for (long i = 0; i < M; i++) {
        cin >> P[i];
    }

    for (long bit = 0; bit < (1 << N); bit++) {
        bool flag = true;
        for (long j = 0; j < M; j++) {
            long counter = 0;
            for (long i = 0; i < N; i++) {
                if (bit & (1 << i) && find(S[j].begin(), S[j].end(), i) != S[j].end()) {
                    counter++;
                }
            }
            if (counter%2 != P[j]) flag = false;
        }
        if (flag) ans++;
    }

    cout << ans << endl;

    return 0;

}