#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int t[N],v[N];
  //  const int tmax=20010;
  const int vmax=103;
  double dp[vmax*2];
  double ndp[vmax*2];
  
  rep(i,N){ cin >> t[i];  }
  rep(i,N) cin >> v[i];
  rep(i,vmax*2){
    dp[i]=-100000.;
  }
    dp[0]=0.;    
  rep(i,N){
    rep1(j,t[i]*2){
      rep(i,vmax*2) ndp[i]=-100000.;
      ndp[0]=max(dp[1]+0.125,dp[0]);	    
      rep1(k,v[i]*2){
	if(dp[k+1]!=-100000.&& k+1<=v[i]*2) ndp[k]=dp[k+1]+(k)/2.*0.5+0.125;
	if(dp[k]!=-100000.) ndp[k]=max(dp[k]+(k)/2.*0.5,ndp[k]);
	if(dp[k-1]!=-100000.){
	  ndp[k]=max(dp[k-1]+(k)/2.*0.5-0.125,ndp[k]);
	}
      }
      //      cout << ndp[v[i]*2] << endl;
      swap(dp,ndp);
    }
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(4) <<  dp[0] << endl;
  return 0;    
}
