#include <bits/stdc++.h>
using namespace std;

// a と b の最大公約数を返す関数
int64_t GCD(int64_t a, int64_t b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    int64_t N, X;
    cin >> N >> X;
    vector<int64_t> x(N+1);
    
    for ( int64_t i = 0; i < N; ++i){
        cin >> x[i];
    }
    x[N] = X;
    sort(x.begin(),x.end());
    
    vector<int64_t> dx(N);
    for ( int64_t i = 0; i < N; ++i){
        dx[i] = x[i+1] - x[i];
    }
    
    int64_t ans = 0;
    if ( N == 1 ){
        ans = x[1] - x[0];
    } else {
        ans = GCD(dx[1],dx[0]);
        for ( int64_t i = 2; i < N; ++i){
            ans = GCD(ans,dx[i]);
        }
    }
    
    cout << ans << endl;
    
    
    
    
    return 0;
}
