


#include <bits/stdc++.h>
using namespace std;

int dp[22][(1<<22)];

int mod=1e9+7;

int matchin(vector<vector<int>> &compat,int i, int n,int womenSubset){

        if(i==n){
            if(womenSubset==0){
                return 1;

            }
            return 0;
        }

        if(dp[i][womenSubset]!=-1){
            return dp[i][womenSubset];
        }

        int ans=0;


        for(int k=0;k<n;k++){

            bool avail=(((1<<k)&(womenSubset))==0)?0:1;

            if(avail && compat[i][k]){
                ans=(ans+matchin(compat,i+1,n,womenSubset^(1<<k)))%mod;
            }


        }

        return dp[i][womenSubset]=ans;



}



int main() {
    int n;
    cin>>n;

    vector<vector<int>> compat(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>compat[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));

    cout<<matchin(compat,0,n,(1<<n)-1);


}
