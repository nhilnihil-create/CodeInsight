#include <bits/stdc++.h>
using namespace std;
long MOD=1e9+7,n,c,p=-1,dp[1<<18],N;
vector<long>v;
map<long,long>m;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>c;
    if(c!=p){
      v.push_back(c);
      p=c;
    }
  }
  if(n==1){
    cout<<1<<endl;
    return 0;
  }
  dp[0]=1;
  m[v[0]]=1;
  N=v.size();
  for(int i=1;i<N;i++)m[v[i]]=dp[i]=(m[v[i]]+dp[i-1])%MOD;
  cout<<dp[N-1]<<endl;
}
