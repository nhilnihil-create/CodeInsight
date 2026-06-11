#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

  ll n,m;
  cin >> n >> m;
  ll a[n];
  for(ll i=0;i<n;i++)cin >> a[i];

  ll s[n+1]={};
  for(ll i=0;i<n;i++)s[i+1]=s[i]+a[i];

  vec v;
  for(ll i=0;i<n+1;i++)v.push_back(s[i]%m);

  sort(v.begin(),v.end());
  vec u=v;
  u.erase(unique(u.begin(),u.end()),u.end());

  ll ans=0;
  for(ll i=0;i<u.size();i++){
    ll p=distance(lower_bound(v.begin(),v.end(),u[i]),upper_bound(v.begin(),v.end(),u[i]));
    ans+=p*(p-1)/2;
    //cout << p << endl;
  }
  cout << ans << endl;

}