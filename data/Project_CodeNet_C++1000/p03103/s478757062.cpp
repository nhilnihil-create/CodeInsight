#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N,M;
    cin >> N >> M;
    vector<int64_t> A(N),B(N);
    for ( int64_t i = 0; i < N; ++i){
        cin >> A[i] >> B[i];
    }
    
    vector<vector<int64_t>> AB(N,vector<int64_t>(2));
    for ( int64_t i = 0; i < N; ++i){
        AB[i][0] = A[i];
        AB[i][1] = B[i];
    }
    
    sort(AB.begin(),AB.end());
    
    
    int64_t count = 0;
    int64_t ans = 0;
    for ( int64_t i = 0; i < N; ++i){
        int64_t cost = AB[i][0];
        int64_t num = AB[i][1];
        if ( count + num <= M ){
            count = count + num;
            ans = ans + cost * num;
        } else {
            ans = ans + cost * ( M - count );
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}
