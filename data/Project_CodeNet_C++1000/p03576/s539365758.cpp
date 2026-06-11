//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n,K;cin>>n>>K;
  vector<P>v(n);
  rep(i,n)cin>>v[i].first>>v[i].second;
  sort(v.begin(),v.end());
  ll ans=INF*5;
  rep(i,n){
    for(ll j=i+K-1;j<n;j++){
      vl part;
      for(ll k=i;k<=j;k++){
        part.push_back(v[k].second);
      }
      sort(part.begin(),part.end());
      ll t=part.size();
      rep(k,t){
        if(k+(K-1)>=t)continue;
        ans=min(ans,(part[k+(K-1)]-part[k])*(v[j].first-v[i].first));
      }
    }
  }
  cout<<ans<<endl;
}
      
  