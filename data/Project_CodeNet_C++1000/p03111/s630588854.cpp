#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N;
    cin >> N;
    int T[3];
    rep(i,3) cin >> T[i];
    vector<int> L(N);
    rep(i,N) cin >> L.at(i);

    int DP[3][1<<8] = {0};
    for(int i = 1; i < 1<<N; i++) {
        rep(j, 3) {
            int WA = 0, num = 0;
            rep(k, N) {
                if (1<<k & i) WA += L[k], num++;
            }
            DP[j][i]= (num - 1) * 10 + abs(T[j] - WA);
        }
    }
    int mi = 1 << 30;
    for (int i = 1; i < 1<<N; i++) for (int j = 1; j < 1<<N; j++) if ((i & j) == 0)
      for (int k = 1; k < 1<<N; k++) if ((i & k) == 0 && (j & k) == 0) {
          mi = min(mi, DP[0][i] + DP[1][j] + DP[2][k]);
      }
    
    cout << mi << endl;
}
