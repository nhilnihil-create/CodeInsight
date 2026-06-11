


#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll inf=1<<19-1;


ll dp[(1<<16)];
ll sums[(1<<16)];

ll calc(vector<vector<int>> &compat, int sub){

    ll ans=0;


    for(int i=0;i<=16;i++){
        for(int j=i+1;j<=16;j++){

            if((sub&(1<<i))!=0 && (sub&(1<<j))!=0){
                ans+=compat[i][j];

            }
        }
    }

    return ans;


}



void prepareSums(vector<vector<int>> &compat,int n){
    

    for(int submask=0;submask<(1<<n);submask++){
        dp[submask]=inf;
        
    }
    sums[0]=0;

    for(int submask=1;submask<(1<<n);submask++){
        sums[submask]=calc(compat,submask);
    }

}



ll maxGrouping(vector<vector<int>> &compat, int mask){

    if(mask==0){
        return 0;

    }
    if(dp[mask]!=inf){
        return dp[mask];
    }

    ll ans=0;

    for(int submask=mask;submask!=0;submask=(submask-1)&mask){

        ans=max(ans,sums[submask]+maxGrouping(compat,mask^submask));

    }

    return dp[mask]=ans;


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
    
    prepareSums(compat,n);

    cout<<maxGrouping(compat,(1<<n)-1);




}
