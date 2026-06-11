# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int N = 17, INF = 1e16;
ll dp[1 << N], group[1 << N], a[N][N], n;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int mask = 0; mask < (1 << n); mask++){
        for(int j = 0; j < n; j++){
            if((mask >> j) & 1){
                for(int k = j + 1; k < n; k++){
                    if((mask >> k) & 1){
                        group[mask] += a[k][j]; 
                    }
                }
            }
        }
        dp[mask] = -INF;
    }
    dp[0] = 0; 
    for(int mask = 0; mask < (1 << n); mask++){
        vector < int > m;
        for(int j = 0; j < n; j++){
            if((mask >> j) & 1)continue;
            m.push_back(j); 
        }
        for(int new_mask = 0; new_mask < (1 << m.size()); new_mask++){
            int next_mask = mask;
            for(int j = 0; j < m.size(); j++){
                if((new_mask >> j) & 1){
                    next_mask |= (1 << m[j]);
                }
            }
            dp[next_mask] = max(dp[next_mask], dp[mask] + group[next_mask ^ mask]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}