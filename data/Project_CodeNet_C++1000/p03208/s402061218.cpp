#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e+15;

int main() {
    int64_t N, K;
    cin >> N >> K;
    
    vector<int64_t> h(N);
    for ( int64_t i = 0; i < N; ++i){
        cin >> h[i];
    }
    
    sort(h.begin(),h.end());
    
    int64_t ans = INF;
    for ( int i = 0; i <= N - K; ++i){
        int64_t dh;
        dh = h[i+K-1] - h[i];
        ans = min(ans,dh);
    }
    
    cout << ans << endl;
    
    return 0;
}
