#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  int N,M;cin>>N>>M;
  //vll x(N),y(N),z(N);rep(i,N)cin>>x[i]>>y[i]>>z[i];
  vector<vll> v(3,vll(N)); rep(i,N)cin>>v[0][i]>>v[1][i]>>v[2][i];
  //+-の取り方8通り
  ll ans=0;
  for(int bit=0;bit<(1<<3);++bit){
    ll ans_each=0;
    vll tmp(N,0);
    rep(i,N){
      for(int mask=0;mask<3;++mask){
        //bit立ってたら+
        if(bit & (1<<mask)){
          tmp[i] += v[mask][i];
        }
        else tmp[i] -= v[mask][i];
      }
    }
    sort(all(tmp),greater<ll>());
    rep(j,M) ans_each += tmp[j];
    ans = max(ans,ans_each);    
  }
  cout << ans << endl;
}