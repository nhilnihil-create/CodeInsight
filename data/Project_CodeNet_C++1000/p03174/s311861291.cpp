#include<bits/stdc++.h>
using namespace std;
int n;
bool arr[23][23];
int M = 1e9+7;
int memo[(1 << 21) + 1] = {};
int dp(int man, int r_wmn){
  if(r_wmn==0)
    return 1;
  if(memo[r_wmn]!=-1)
    return memo[r_wmn];
  int num=0;
  for(int i=0;i<n;i++){
    if(!arr[man][n-i-1] || !(r_wmn&(1<<i)))
      continue;
      num+=dp(man+1,r_wmn^(1<<i));
    num=num%M;
  }
  memo[r_wmn]=num;
  return num;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>arr[i][j];
  memset(memo,-1,sizeof(memo));
  int res=dp(0,(1<<n)-1);
  cout<<res<<"\n";
}