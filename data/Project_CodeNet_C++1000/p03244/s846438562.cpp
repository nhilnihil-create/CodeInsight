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

  ll n;
  cin >> n;
  ll v[n/2],u[n/2];
  for(ll i=0;i<n/2;i++)cin >> v[i] >> u[i];
  vec a(100001),b(100001);
  vec c,d;
  for(ll i=0;i<n/2;i++){
    a[v[i]]++;
    b[u[i]]++;
  }
  ll p=0,q=0;
  for(ll i=0;i<100001;i++){
    p=max(p,a[i]);
    q=max(q,b[i]);
  }

  for(ll i=0;i<100001;i++){
    if(p==a[i])c.push_back(i);
    if(q==b[i])d.push_back(i);
  }

  if(c.size()==1 && d.size()==1 && c[0]==d[0]){
    ll s=0,t=0;
    for(ll i=0;i<100001;i++){
      if(i!=c[0])s=max(s,a[i]);
      if(i!=d[0])t=max(t,b[i]);
    }
    ll ans=min(n-q-s,n-t-p);
    cout << ans << endl;
  }
  else{
    cout << n-p-q << endl;
  }

}