#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,k;
  int h[100005];
  int dp[100005]={};
  int m;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  for(int i=1;i<n;i++){
    if(i==1){
      dp[i]=abs(h[i]-h[i-1]);
    }
    else{
      m=INF;
      for(int j=1;j<=k;j++){
	if(m>abs(h[i]-h[i-j])+dp[i-j]){
	  m=abs(h[i]-h[i-j])+dp[i-j];
	}
	if(i-j==0){
	  j+=k;
	}
      }
      dp[i]=m;
    }
  }
  cout<<dp[n-1]<<"\n";

  return 0;
}
