#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
int dp[1<<21][21];

vector<int> a[21];
int DONE,n;

int solve(int bitmask, int ind){
    // base case
    if(bitmask==DONE){
        return 1;
    }
    if(ind>=n)
        return 0;
    if(dp[bitmask][ind]!=-1)
        return dp[bitmask][ind];
    int ans = 0;
    //cout<<"printing  "<<bitmask<<ind<<endl;
    for(int aa:a[ind]){
        //cout<<"printing  "<<bitmask<<" "<<ind<<endl;
        if((bitmask&(1<<aa))==0)
        ans+=solve(bitmask|(1<<aa),ind+1);
        ans%=mod;
    }
    //ans+=solve(bitmask,ind+1);
    ans%=mod;
    return dp[bitmask][ind]=ans;
}

int main()
{
    cin>>n;
    int x;
    DONE = (1<<n) - 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            //cout<<x<<endl;
            if(x==1)
                a[i].push_back(j);
        }
    }/*
    for(int i=0;i<n;i++){
        for(int aa:a[i])
            cout<<aa;
        cout<<endl;
    }*/
    memset(dp,-1,sizeof(dp));
    int ans = solve(0,0);
    cout<<ans<<'\n';
    return 0;
}