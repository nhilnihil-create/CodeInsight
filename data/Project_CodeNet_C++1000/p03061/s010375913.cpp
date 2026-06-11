#include <bits/stdc++.h>
using namespace std;

// a と b の最大公約数を返す関数
int64_t GCD(int64_t a, int64_t b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for ( int64_t i = 0; i < N; ++i){
        cin >> A[i];
    }
    
    vector<int64_t> L(N); // 左からi番目までの最大公約数
    vector<int64_t> R(N); // 左からi番目までの最大公約数
    
    L[0] = A[0];
    for ( int64_t i = 1; i < N; ++i){
        L[i] = GCD(L[i-1],A[i]);
    }
    R[N-1] = A[N-1];
    for ( int64_t i = N-2; i >= 0; --i){
        R[i] = GCD(R[i+1],A[i]);
    }
    
    int64_t ans = 1;
    for ( int64_t i = 0; i < N; ++i){
        int64_t LR;
        if ( i == 0 ){
            LR = R[1];
        } else if ( i == N-1 ){
            LR = L[N-2];
        } else {
            LR = GCD(L[i-1],R[i+1]);
        }
        ans = max(ans,LR);
    }
    cout << ans << endl;
    
    
    return 0;
}