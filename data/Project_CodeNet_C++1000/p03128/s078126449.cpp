#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 3e18+7
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<pair<int,ll>,ll> p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};

int C[10],need[10]={0,2,5,5,4,5,6,3,7,6};
int dp[11000];

int main(){
  int N,M;
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int a;
    cin>>a;
    C[a]++;
  }
  for(int i=1;i<=9;i++){
    if(C[i]==0){
      C[i]=-1;
    }else{
      C[i]=need[i];
    }
  }
  for(int i=0;i<11000;i++){
    dp[i]=-10000;
  }
  dp[0]=0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=9;j++){
      if(C[j]==-1) continue;
      if(i-C[j]<0) continue;
      dp[i]=max(dp[i],dp[i-C[j]]+1);
    }
  }
  //cout<<dp[N]<<endl;
  int num=dp[N];
  while(num!=0){
    //cout<<N<<endl;
    for(int i=9;i>=0;i--){
      if(C[i]>=0 && N-C[i]>=0 && dp[N]==dp[N-C[i]]+1){
        cout<<i;
        N-=C[i];
        num--;
        break;
      }
    }
  }
  cout<<endl;

}
