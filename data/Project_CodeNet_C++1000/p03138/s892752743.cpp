#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<double,ll,ll>T;
#define PI 3.14159265358979
const int MOD = 1e9 + 7;

int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll>A(N);
  rep(i,N){
  	cin>>A[i];
  }
  vector<ll>a(45);
  rep(i,45){a[i]=0ll;}
  rep(i,N){
    ll p=A[i];
  	rep(j,45){
    	if(p%2ll==1ll){a[j]++;}
      	p/=2ll;
    }
  }
  ll dp[45][2];
  rep(i,45){dp[i][0]=-1ll;dp[i][1]=-1ll;}
  dp[44][0]=0ll;
  for(int i=43;i>=0;i--){
    if(dp[i+1][1]>=0){
      dp[i][1]=max(dp[i][1],dp[i+1][1]+a[i]*(ll)pow(2ll,i));
      dp[i][1]=max(dp[i][1],dp[i+1][1]+(N-a[i])*(ll)pow(2ll,i));
    }
	if(K&(1ll<<i)){
      dp[i][1]=max(dp[i][1],dp[i+1][0]+a[i]*(ll)pow(2ll,i));
      dp[i][0]=max(dp[i][0],dp[i+1][0]+(N-a[i])*(ll)pow(2ll,i));
    }
    else{
      dp[i][0]=max(dp[i][0],dp[i+1][0]+a[i]*(ll)pow(2ll,i));
    }
  }
  cout<<max(dp[0][0],dp[0][1])<<endl;
  
} 
