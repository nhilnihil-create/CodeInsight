# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N = 16, INF = 1e16;
ll dp[1 << N], group[1 << N], a[N][N], n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(((mask >> i) & 1) && (mask >> j) & 1){
                    group[mask] += a[i][j];
                }
            }
        }
        dp[mask] = -INF;
    }
    dp[0] = 0; 
    for(int mask = 0; mask < (1 << n); mask++){
        int comp_mask = (1 << n) - mask - 1;
        for(int new_mask = comp_mask; new_mask; new_mask = (new_mask - 1) & comp_mask){
            int next_mask = new_mask ^ mask;
            dp[next_mask] = max(dp[next_mask], dp[mask] + group[new_mask]); 
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}