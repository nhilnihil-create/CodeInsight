#include <bits/stdc++.h>
using namespace std;
struct activity{
    public:
    int A,B,C;
};
int a[100000];
int dp[100000][3];

int solve(vector<activity> &ar,int n){
   memset(dp, 0, sizeof dp);
   dp[0][0]=ar[0].A;
   dp[0][1]=ar[0].B;
   dp[0][2]=ar[0].C;


      for(int i=1;i<n;++i){
      dp[i][0]= ar[i].A  + max(dp[i-1][1], dp[i-1][2]);
      dp[i][1]= ar[i].B  + max(dp[i-1][0], dp[i-1][2]);
      dp[i][2]= ar[i].C  + max(dp[i-1][1], dp[i-1][0]);
      }

  
  return max(dp[n-1][0],max(dp[n-1][1], dp[n-1][2])); 
}
int main() {
    vector<activity> ar;
    int n; cin>>n;
    for(int i=n;i>0;--i){
       activity ac;
       cin>>ac.A>>ac.B>>ac.C;
       ar.push_back(ac);
    }
    cout<<solve(ar, n);

    return 0;
}
