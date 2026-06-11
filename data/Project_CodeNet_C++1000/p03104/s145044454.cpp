#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

const int INF = 1001001001;

#define rep(i, n) for(ll i = 0; i < (int)(n); i++)


int main() {
  vector<ll> v(2);
  vector<ll> d(2);
  cin>>v[0]>>v[1];
  if (v[0]>0)v[0]--;
//  vector<ll>v(b+1);
  rep(i,2){

    ll c=v[i]%4;
    ll now=0;
    if (c==0) now=v[i];
    if (c==1) now=1;
    if (c==2) now=(v[i] ^ 1);
    d[i]=now;
  //  cout<<now<<endl;
  }

  ll ans=d[1]^d[0];
  cout<<ans;
}
