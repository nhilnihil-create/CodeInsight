#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<vector<ll>> DP(N+1, vector<ll>(2,0));
    DP[0][0] = 0;
    DP[0][1] = -9999999999;
    int cnt = 0;
    rep(i,N) {
        DP[i+1][0] = max(DP[i][0]+A[i], DP[i][1]-A[i]);
        DP[i+1][1] = max(DP[i][0]-A[i], DP[i][1]+A[i]);
//        printf("%18ld %18ld\n", DP[i+1][0], DP[i+1][1]);
    }
    cout << DP[N][0] << endl;
}
