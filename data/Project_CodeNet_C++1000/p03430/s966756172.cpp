#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll dp[305][305][305]={0};
bool used[305][305][305]={0};
string s;
ll get_dp(ll i,ll j,ll k){
  if(i==j) return dp[i][j][k]=1;
  else if(i+1==j){
    if(k==0) return dp[i][j][k]=(s[i]==s[j]?2:1);
    else return dp[i][j][k]=2;
  }
  else if(used[i][j][k]>0) return dp[i][j][k];
  used[i][j][k]=true;
  dp[i][j][k]=max(get_dp(i+1,j,k),get_dp(i,j-1,k));
  if(s[i]==s[j]) dp[i][j][k]=max(dp[i][j][k],get_dp(i+1,j-1,k)+2);
  else if(k>0) dp[i][j][k]=max(dp[i][j][k],get_dp(i+1,j-1,k-1)+2);
  return dp[i][j][k];
}
int main(){
  cin>>s;
  ll k;
  cin>>k;
  for(int i=0;i<305;i++){
    for(int j=0;j<305;j++){
      for(int l=0;l<305;l++) used[i][j][l]=false;
    }
  }
  cout<<get_dp(0,s.length()-1,k)<<endl;
}
