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

  ll n,k;
  cin >> n >> k;
  ll a[n];
  rep(i,n){
    cin >> a[i];
  }

  ll sum[n+1];
  sum[0]=0;
  rep1(i,n){
    sum[i]=a[i-1];
    sum[i]+=sum[i-1];
  }
  vector<ll> all;
  rep(i,n){
    for(int j=i;j<n;j++){
      all.pb(sum[j+1]-sum[i]);
    }
  }
  for(int i=40; i>=0; i--){
    int c=0;
    vector<ll> nxt;
    rep(j,all.size()){
      if((1LL<<i)&all[j]){
	c++;
	nxt.pb(all[j]);
      }      
    }
    if(c>=k){
      all.clear();
      rep(m,nxt.size()){
	all.pb(nxt[m]);
      }
      //      cout << i << endl;
    }
  }
  ll ans=all[0];
  rep(i,all.size()){
    //  cout << all[i] << endl;
    ans&=all[i];
  }
  cout << ans << endl;
  return 0;
    

}
