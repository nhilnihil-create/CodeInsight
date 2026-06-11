#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int nax=20;
const ll INF=1e18L+5;
ll values[nax][nax];
vector<ll> pre;
vector<ll> dp;

void rec(int i,vector<int>& ava,ll score_so_far,int mask,int group){
    if(i==ava.size()){
        dp[mask]=max(dp[mask],score_so_far+pre[group]);
        return;
    }
    rec(i+1,ava,score_so_far,mask,group);
    rec(i+1,ava,score_so_far,mask^(1<<ava[i]),group^(1<<ava[i]));
}

int main()
{
  int n;cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>values[i][j];
    }
  }
  pre.resize((1<<n));

  for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                for(int j=i+1;j<n;j++){
                    if(mask&(1<<j)){
                        pre[mask]+=values[i][j];
                    }
                }
            }
        }

  }

  dp=vector<ll> (1<<n,-INF);
  dp[0]=0;
   for(int i=0;i<(1<<n);i++){
        vector<int>ava;
     for(int j=0;j<n;j++){
        if(!(i&(1<<j))){
            ava.push_back(j);
        }
     }
     rec(0,ava,dp[i],i,0);
   }
  cout<<dp[(1<<n)-1];
}
