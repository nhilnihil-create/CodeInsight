#include <bits/stdc++.h>
using namespace std;

void chmin(int64_t& a, int64_t b){
    a = min(a, b);
}

int main(){
    int N;
    int64_t A, B;
    cin >> N >> A >> B;
    int pos[5001];
    for(int i=0; i<N; i++){
        int p;
        cin >> p;
        pos[p-1] = 2*i+1;
    }

    const int64_t INF = 1e18;
    static int64_t dp[5001][10001];
    for(int i=1; i<=N; i++) for(int j=0; j<=2*N; j++) dp[i][j] = INF;

    for(int i=0; i<N; i++){
        int64_t mn = INF;
        for(int j=0; j<=2*N; j++){
            chmin(mn, dp[i][j]);
            if(pos[i] == j){
                chmin(dp[i+1][j], mn);
            }else if(j%2 == 0){
                int64_t cost = (pos[i] < j ? A : B);
                chmin(dp[i+1][j], mn + cost);
            }
        }
    }

    int64_t ans = INF;
    for(int j=0; j<=2*N; j++) chmin(ans, dp[N][j]);
    cout << ans << endl;
    return 0;
}
