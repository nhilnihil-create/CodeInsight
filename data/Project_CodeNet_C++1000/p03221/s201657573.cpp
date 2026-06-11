#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

Int power(Int a, Int n) {
    Int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int main() {
    Int N, M;
    cin >> N >> M;
    map<Int,Int> f;
    vector<Int> P(M), Y(M);
    vector<vector<Int>> G(N);

    rep(i,M) {
        cin >> P[i] >> Y[i];
        P[i]--;
        f[Y[i]] = i;
        G[P[i]].push_back(Y[i]);
    }

    vector<string> distnum(M, "");

    rep(i,N) {
        if (G[i].size() != 0) {
            sort(G[i].begin(),G[i].end());
            rep(j,G[i].size()) {
                rep(k,6) {
                    distnum[f[G[i][j]]] += ('0' + ((i+1)/power(10,5-k))%10);
                }
                rep(k,6) {
                    distnum[f[G[i][j]]] += ('0' + ((j+1)/power(10,5-k))%10);
                }
            }
        }
    }

    rep(i,M) cout << distnum[i] << endl;

}