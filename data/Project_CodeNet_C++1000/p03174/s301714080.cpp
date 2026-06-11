#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
int N;


int main(){
    cin>>N;
    vector<vector<int>> compatible(N, vector<int> (N));
    vector<int> dp (1 << N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>compatible[i][j];
        }
    }

    dp[0] = 1;

    for(int mask = 0; mask < (1 << N) - 1; mask++){
        int man = __builtin_popcount(mask);
        for(int j = 0; j < N; j++){
            if((mask & (1 << j)) == 0 && compatible[man][j] == 1){
                int temp = mask | (1 << j);
                dp[temp] += dp[mask];
                dp[temp] %= mod;
            }
        }
    }

    cout<<dp[(1 << N)-1];

    return 0;
}
