#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int X[505][505];
int C[505][505];

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<int> L(M), R(M);
    rep(i, M){
        cin >> L[i] >> R[i];
        X[L[i]][R[i]]++;
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            C[i][j] = C[i][j-1] + X[i][j];
        }
    }

    rep(k, Q){
        int p, q; cin >> p >> q;
        int ans = 0;
        for (int i = p; i <= q; i++){
            ans += C[i][q] - C[i][p-1];
        }
        cout << ans << endl;
    }

    return 0;
}