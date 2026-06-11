#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  string s;cin>>s;
  ll q;cin>>q;
  vector<ll> d,m,c;
  for(ll i=0;i<n;i++){
    if(s[i]=='D')d.push_back(i);
    if(s[i]=='M')m.push_back(i);
    if(s[i]=='C')c.push_back(i);
  }
  ll sum[n+1];
  sum[0]=0;
  for(ll i=0;i<c.size();i++){
    ll y=lower_bound(m.begin(),m.end(),c[i])-m.begin();
    sum[i+1]=sum[i]+y;
  }
  ll dm[2000010],dc[2000010];
  for(ll i=0;i<2000001;i++){
    ll mm=lower_bound(m.begin(),m.end(),i)-m.begin();
    ll cc=lower_bound(c.begin(),c.end(),i)-c.begin();
    dm[i]=mm;dc[i]=cc;
  }
  for(ll i=0;i<q;i++){
    ll k;cin>>k;
    ll ans=0;
    for(ll j=0;j<d.size();j++){
      ll rc=dc[d[j]+k],lc=dc[d[j]],lm=dm[d[j]];
      ans+=(sum[rc]-sum[lc])-(rc-lc)*lm;
    }
    cout<<ans<<endl;
  }
}
  