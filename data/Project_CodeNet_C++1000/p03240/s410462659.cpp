#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
ll mod = 1000000007;
int main(){
  ll n; cin >> n;
  vector<vector<ll>> v(n,vector<ll>(3,0));
  rep(i,n){
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }
  rep(x,101)rep(y,101){
    set<ll> s;
    vector<ll> yobi(3);
    ll cnt=0;
    for(auto t:v){
      if(t[2]==0) continue;
      cnt++;
      s.insert(abs(t[0]-x)+abs(t[1]-y)+t[2]);
      yobi[0]=t[0];yobi[1]=t[1];yobi[2]=t[2];
    }
    if(cnt==1){
      printf("%lld %lld %lld",yobi[0],yobi[1],yobi[2]);
      return 0;
    }
    if(s.size()==1){
      for(auto t:v){
        if(t[2]==0) continue;
        ll h = abs(t[0]-x)+abs(t[1]-y)+t[2];
        printf("%lld %lld %lld",x,y,h);
        return 0;
      }
    }
  }
  return 0;
}