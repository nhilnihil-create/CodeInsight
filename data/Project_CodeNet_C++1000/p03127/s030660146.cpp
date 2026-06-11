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
    
    int64_t ans = A[0];
    for ( int64_t i = 1; i < N; ++i){
        ans = GCD(ans,A[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}

