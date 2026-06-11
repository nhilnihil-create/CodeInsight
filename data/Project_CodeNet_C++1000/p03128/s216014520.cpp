#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int b[12]={(1<<29),2,5,5,4,5,6,3,7,6};
  int INF=(1<<29);
  int n,m,a,i,j;
  vector<int> x(12),dp(10010,-INF);
  vector<int> ans;
  scanf("%d %d\n",&n,&m);
  for(i=0;i<m;i++){
    scanf("%d ",&a);
    x[a]=1;
  }
  dp[0]=0;
  for(i=0;i<=n;i++){
    for(j=1;j<10;j++){
      if(x[j]==0){
        continue;
      }
      if(i+b[j]<=n){
        dp[i+b[j]]=max(dp[i+b[j]],dp[i]+1);
      }
    }
  }
  for(i=n;i>0;){
    for(j=9;j>0;j--){
      if(x[j]==0){
        continue;
      }
      if(i-b[j]>=0 && dp[i]==dp[i-b[j]]+1){
        ans.push_back(j);
        i=i-b[j];
        break;
      }
    }
  }
  sort(ans.begin(),ans.end(),greater<int>());
  for(i=0;i<ans.size();i++){
    printf("%d",ans[i]);
  }
  printf("\n");
  return 0;
}