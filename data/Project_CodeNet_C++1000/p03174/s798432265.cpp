#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;
const int nax=22;
vector<vector<ll>> dp(1<<nax,vector<ll>(nax,-1));

ll calc(int index,int mask,int& size,vector<vector<int>>& pairs,int& n){
  if(mask==size){
    return 1;
  }
   if(index>=n) return 0;
   if(dp[mask][index]!=-1) return dp[mask][index];
   ll res=0;
   for(int i=0;i<n;i++){
     int val=(mask>>i)&1;
     if(!val && pairs[index][i]){
        res+=calc(index+1,mask|(1<<i),size,pairs,n);
         if(res>mod)
            res-=mod;
     }
   }
   dp[mask][index]=res;
   return res;
}

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<vector<int>> pairs(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>pairs[i][j];
    }
    int size=(1<<n)-1;
    cout<<calc(0,0,size,pairs,n);

}
