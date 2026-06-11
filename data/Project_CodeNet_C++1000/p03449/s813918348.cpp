#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<std::vector<long long>> A){
    vector<vector<long long> > C(2);
    vector<long long> temp_c(N+1, 0);
    for(int i = 0; i < N; ++i){
        temp_c[i+1] = temp_c[i] + A[0][i];
    }
    //for(auto i : temp_c) cout << i << endl;
    C[0] = temp_c;
    temp_c.clear();
    temp_c.resize(N+1);
    for(int i = N; i > 0; --i){
        temp_c[i-1] = temp_c[i] + A[1][i-1];
    }
    //for(auto i : temp_c) cout << i << endl;
    C[1] = temp_c;
    long long ans = 0;
    for(int i = 1; i < N+1; ++i) ans = max(ans, C[0][i] + C[1][i-1]);
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<std::vector<long long>> A(2, std::vector<long long>(N));
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < N ; j++){
            scanf("%lld",&A[i][j]);
        }
    }
    solve(N, std::move(A));
    return 0;
}
