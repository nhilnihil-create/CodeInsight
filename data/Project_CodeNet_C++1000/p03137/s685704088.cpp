#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N,M;
    cin >> N >> M;
    vector<int64_t> X(M);
    for ( int64_t i = 0; i < M; ++i){
        cin >> X[i];
    }
    sort(X.begin(),X.end());
    vector<int64_t> DX(M-1);
    for ( int64_t i = 0; i < M-1; ++i){
        DX[i] = X[i+1] - X[i];
    }
    
    sort(DX.begin(),DX.end());
    
    int64_t res = 0;
    for ( int64_t i = 0; i < M-N; ++i){
        res = res + DX[i];
    }
    cout << res << endl;
    
    
    return 0;
}
