#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin>>n;
  vector<pair<ll,ll>> r(n),b(n);
  for(ll i=0;i<n;i++)
    cin>>r[i].first>>r[i].second;;
  for(ll i=0;i<n;i++)
    cin>>b[i].first>>b[i].second;
  sort(r.begin(),r.end());
  sort(b.begin(),b.end());
  multiset<ll> pts;
  ll ans =0;
  ll i,j;
  for(i=0,j=0;i<n && j<n;){
    if(r[i]<b[j])
    	{pts.insert(r[i].second);i++;}
    else if(pts.lower_bound(b[j].second) != pts.begin())
    {ans++;pts.erase(--(pts.lower_bound(b[j].second)));j++;}
    else {j++;}
  }
  while(j<n){
  	if(pts.lower_bound(b[j].second) != pts.begin())
    {ans++;pts.erase(--(pts.lower_bound(b[j].second)));j++;}
    else {j++;}
  }
  cout<<ans;
}