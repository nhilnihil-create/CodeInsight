#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const double pi=acos(-1);


int main(){
  int A,B,Q;
  cin >> A >> B >> Q;
  vector<ll>s(A+2);
  vector<ll>t(B+2);
  rep(i,A) cin >> s[i+1];
  rep(i,B) cin >> t[i+1];
  s[0]=-1e18;
  t[0]=-1e18;
  s[A+1]=1e18;
  t[B+1]=1e18;
  rep(i,Q){
    ll x;
    cin >> x;
    ll b = lower_bound(s.begin(),s.end(),x)-s.begin();
    ll d = lower_bound(t.begin(),t.end(),x)-t.begin();
    ll a = b-1;
    ll c = d-1;
    
    ll ans=1e18;
    
    ll saki;
    ll ato;
    rep(i,2){
      if(i==0) saki = s[a];
      else saki = s[b];
      rep(j,2){
        if(j==0) ato = t[c];
        else ato = t[d];
        if(ans>abs(x-saki)+abs(saki-ato))ans=abs(x-saki)+abs(saki-ato);
      }
    }
    rep(i,2){
      if(i==0) saki = t[c];
      else saki = t[d];
      rep(j,2){
        if(j==0) ato = s[a];
        else ato = s[b];
        if(ans>abs(x-saki)+abs(saki-ato))ans=abs(x-saki)+abs(saki-ato);
      }
    }
    
    cout << ans << endl;
  }
  return 0;

}
