/*修正*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  ll n,m,q;
  cin>>n>>m>>q;
  ll a[510][510],b[510][510];
  for(ll i=0;i<m;i++){
    ll l,r;
    cin>>l>>r;
    a[r][l]++;
  }
  for(ll i=0;i<=500;i++){
    for(ll j=0;j<=500;j++){
      b[i][j+1]=a[i][j]+b[i][j];
    }
  }
  for(ll i=0;i<q;i++){
    ll c,d;
    cin>>c>>d;
    ll ans=0;
    for(ll j=c;j<=d;j++){
      ans+=b[j][d+1]-b[j][c];
    }
    cout<<ans<<endl;
  }
  return 0;
}