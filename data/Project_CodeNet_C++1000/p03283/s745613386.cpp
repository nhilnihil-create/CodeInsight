#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> city(N+1, vector<int>(N+1));
    int L, R;
    rep(i, M) {
        cin >> L >> R;
        city[R][L]++;
    }
    /*for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (j) cout << " ";
            cout << city[i][j];
        }
        cout << endl;
    }
    cout << endl;*/
    for (int i = 0; i < N; i++) {
        for (int j = i; j >= 0; j--) {
            city[i+1][j] += city[i][j];
        }
    }
    for (int i = 0; i <= N; i++) {
        for (int j = i; j > 0; j--) {
            city[i][j-1] += city[i][j];
        }
    }
    int p, q;
    /*for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (j) cout << " ";
            cout << city[i][j];
        }
        cout << endl;
    }*/
    rep(i, Q) {
        cin >> p >> q;
        cout << city[q][p] << endl;
    }
}
