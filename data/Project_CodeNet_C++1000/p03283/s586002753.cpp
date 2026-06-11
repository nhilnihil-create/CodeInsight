#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    int rail[N+2][N+2] = {};
    int li, ri;
    rep(i, M) {
        cin >> li >> ri;
        rail[li][ri]++;
    }

    int acc[N+2][N+2] = {};
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        acc[i][j] = acc[i][j-1] + acc[i-1][j] - acc[i-1][j-1] + rail[i][j];
    } 

    int S[Q], E[Q];
    rep(i, Q) cin >> S[i] >> E[i];

    rep(i, Q) {
        int s = S[i], e = E[i];
        cout << acc[e][e] - acc[s-1][e] - acc[e][s-1] + acc[s-1][s-1] << endl;
    }

    return 0;
}

