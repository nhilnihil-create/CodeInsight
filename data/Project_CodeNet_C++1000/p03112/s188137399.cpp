#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

const ll INF = 1e18;

#define rep(i, n) for(ll i = 0; i < (int)(n); i++)

int main() {
  ll a,b,q;
  cin>>a>>b>>q;
  vector<ll> s(a+2);
  vector<ll> t(b+2);
  vector<ll> x(q);
  vector<ll> S(q);
  vector<ll> T(q);
  s[0]=-INF;
  t[0]=-INF;
  s[a+1]=INF;
  t[b+1]=INF;

  rep(i,a)cin>>s[i+1];
  rep(i,b)cin>>t[i+1];
  rep(i,q){
    ll ans=INF;
    cin>>x[i];
    ll si=lower_bound(s.begin(),s.end(),x[i])-s.begin();
    //S[i]=now;
    ll ti=lower_bound(t.begin(),t.end(),x[i])-t.begin();
  //  T[i]=now;
    ll lft=max(abs(x[i]-s[si-1]),abs(x[i]-t[ti-1]));
    ll rt=max(abs(x[i]-s[si]),abs(x[i]-t[ti]));
    ll lr=min(abs(x[i]-s[si-1])+abs(s[si-1]-t[ti]),abs(x[i]-t[ti])+abs(s[si-1]-t[ti]));
    ll rl=min(abs(x[i]-s[si])+abs(s[si]-t[ti-1]),abs(x[i]-t[ti-1])+abs(s[si]-t[ti-1]));

    ans=min(rt,lft);
    ans=min(ans,lr);
    ans=min(ans,rl);
    cout<<ans<<endl;
  ///  cout<<lft<<' '<<rt<<' '<<lr<<' '<<rl<<endl;


  }




}
