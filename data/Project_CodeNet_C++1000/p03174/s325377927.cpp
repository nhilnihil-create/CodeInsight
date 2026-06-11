#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int t;
const int MOD=1e9+7;

void add_self(int &a, int b){
    a+=b;
    if(a>=MOD)a-=MOD;
}

void test_case(){
    int n;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)cin>>grid[i][j];
    vector<int>dp(1<<n); // how many ways to pair __builtin_popcount(i)th boy with b'th bit girl in state i;
    dp[0]=1;
    for(int mask=0; mask<1<<n; mask++){
        int b=__builtin_popcount(mask);
        for(int g=0; g<n; g++){
            int n_mask=mask|(1<<g);
            if(!((1<<g)&mask) && grid[b][g]){
                add_self(dp[n_mask],dp[mask]);
            }
        }
    }

    cout<<dp[(1<<n)-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }

    return 0;
}