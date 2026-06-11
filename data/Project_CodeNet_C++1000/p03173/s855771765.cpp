#include <bits/stdc++.h> 
using namespace std;
#define ll long long 

ll dp[3001][3001];
ll sum[3001][3001];


void prepocess(vector<int>& v,int n){
    
    for(int i=1;i<=n;i++){
       for(int j=i;j<=n;j++){
          sum[i][j]=v[j]+((j==i)? 0 : sum[i][j-1]);
       }
    }
}



ll solve(vector<int>& v,int i,int j){

   if(i==j){
      return 0;
   }
   if(dp[i][j]!=-1){
      return dp[i][j];
   }
   ll min_cost=(1LL<<60);
   for(int k=i;k<j;k++){
       min_cost=min(min_cost,sum[i][j]+solve(v,i,k)+solve(v,k+1,j));
   }
  return dp[i][j]=min_cost;

}



int main() {
  
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n;
  cin>>n;
  memset(dp,-1,sizeof dp);
  vector<int> v(n+1);
  for(int i=1;i<=n;i++){
      cin>>v[i];
  }
  prepocess(v,n);
  cout<<solve(v,1,n)<<endl;
  return 0;

}    