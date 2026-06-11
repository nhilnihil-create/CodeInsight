#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 1000000007
typedef long long ll;
using namespace std;

pair<ll,ll> dp[300030];

int main(){
  int n;
  cin>>n;
  int m=pow(2,n);
  ll A[m+1]={};
  for(int i=0;i<m;i++){
      cin>>A[i];
  }

  for(int i=1;i<m;i++) dp[i]=make_pair(i,0);
  dp[0]=make_pair(0,m);

  for(int i=1;i<m;i++){
      set<int> se;
      for(int j=18;j>=0;j--){
          if((1<<j)&i){
              int z=i^(1<<j);
              se.insert(dp[z].first);
              se.insert(dp[z].second);
          }
      }
      se.insert(0);
      se.insert(i);
      
      int ma1=0,ma2=0;
      int index1=0,index2=0;
      for(auto s:se){
          if(ma1<A[s]){
              ma2=ma1;
              index2=index1;
              ma1=A[s];
              index1=s;
          }else if(ma2<A[s]){
              ma2=A[s];
              index2=s;
          }
      }
      dp[i]=make_pair(index1,index2);
  }

  ll ans[m+1]={};
  for(int i=1;i<m;i++){
      ans[i]=A[dp[i].first]+A[dp[i].second];
      ans[i]=max(ans[i],ans[i-1]);
      cout<<ans[i]<<endl;
  }

  return 0;
}
