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
  int n;
  cin >> n;
  int w,s;
  ll v;
  vector<tuple<int,int,ll> > info(n);
  //  cout << info.size() << endl;
  rep(i,n){
    cin >> w >> s >> v;
    info[i]=make_tuple(w,s,v);
  }
  sort(info.begin(), info.end(),[](tuple<int,int,ll> a,tuple<int,int,ll> b){
				  int sa=get<1>(a);
				  int sb=get<1>(b);
				  int wa=get<0>(a);
				  int wb=get<0>(b);
				  return min(sa,sb-wa) > min(sb,sa-wb);
				});
  int w_max=3e4;
  ll dp[w_max];
  ll ndp[w_max];
  rep(i,w_max) dp[i]=0;
  rep(i,w_max) ndp[i]=0;
  rep(i,n){
    rep(j,get<1>(info[i])+1){
      int nw=j+get<0>(info[i]);
      if(nw<w_max){
	ndp[nw]= max(dp[nw], dp[j]+get<2>(info[i]));
      }
    }
    rep(i,w_max) dp[i]=ndp[i];
  }
  ll ans=0;
  rep(i,w_max){
    //    if(dp[i]!=0) cout << "i dp " << i << " " << dp[i] << endl;
    ans=max(ans,dp[i]);
  }
  cout << ans << endl;

  return 0;
    

}
