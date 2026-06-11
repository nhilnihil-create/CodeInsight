#include<bits/stdc++.h>
using namespace std;
int getMaxPoint(vector<int> v,int &p){
  int point=INT_MIN,act=-1;
    for(int i=0;i<3;i++){
      if(i==p)
        continue;
      if(v[i]>point){
        point=v[i];
      act=i;
      }
    }
  p=act;
  return point;
}
int main(){
  int n;
  cin>>n;
  vector<vector<int> > vac(n,vector<int> (3));
  for(int i=0;i<n;i++){
    cin>>vac[i][0]>>vac[i][1]>>vac[i][2];
  }
  int activity=-1;
  vector<vector<int> > dp(n,vector<int> (3));
  dp[0]=vac[0];
  for(int i=1;i<n;i++){
    dp[i][0]=vac[i][0]+max(dp[i-1][1],dp[i-1][2]);
    dp[i][1]=vac[i][1]+max(dp[i-1][0],dp[i-1][2]);
    dp[i][2]=vac[i][2]+max(dp[i-1][0],dp[i-1][1]);
  }
 cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
  return 0;
}