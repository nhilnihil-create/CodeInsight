#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N+2);
    rep(i,N) cin >> A.at(i+1);
    A[0] = 0;
    A[N+1] = 0;
    vector<ll> B(N+1);
    int all = 0;
    for (int i = 0; i < N+1; i++) {
        B.at(i) = abs(A.at(i+1) - A.at(i));
        all += B[i];
    }
    for (ll i = 1; i <= N; i++) {
       int res = 0;
       if (i == 1) res = all - B[0] - B[1] + abs(A[2]);
       else if (i == N) res = all - B[N-1] - B[N] + abs(A[N-1]);
       else res = all - B[i-1] -B[i] + abs(A[i+1] - A[i-1]);
       cout << res << endl;
    }
}
