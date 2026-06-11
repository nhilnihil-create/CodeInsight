#include<bits/stdc++.h>
using namespace std;

class activity{
  public:
  int A,B,C;
};

int vacation(vector<activity> a, int n){
  int dp[100005][3];
  dp[1][0]=a[1].A;
  dp[1][1]=a[1].B;
  dp[1][2]=a[1].C;
  for(int i=2;i<=n;i++){
  	dp[i][0] = a[i].A + max(dp[i-1][1],dp[i-1][2]);
    dp[i][1] = a[i].B + max(dp[i-1][0],dp[i-1][2]);
    dp[i][2] = a[i].C + max(dp[i-1][1],dp[i-1][0]);
  }
  return max(dp[n][0],max(dp[n][1],dp[n][2]));
}


int main(){
  int n;	cin>>n;
  vector<activity> a(n+1);
  for(int i=1;i<=n;i++){
  	cin>>a[i].A;
    cin>>a[i].B;
    cin>>a[i].C;
  }
  cout<<vacation(a,n);
  return 0;
}