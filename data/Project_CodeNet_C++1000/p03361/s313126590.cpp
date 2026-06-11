#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll h,w;
  cin >> h >> w;
  vector<string> s(h);
  for(ll i=0;i<h;i++) cin >> s[i];
  ll f=1;
  vec idx={1,0,-1,0};
  vec idy={0,1,0,-1};
  for(ll i=0;i<h;i++) {
    for(ll j=0;j<w;j++) {
      if(s[i][j]=='#') {
        ll ff=0;
        for(ll k=0;k<4;k++) {
          ll ny=i+idy[k];
          ll nx=j+idx[k];
          if(nx<0||ny<0||nx>w-1||ny>h-1) continue;
          if(s[ny][nx]=='#') ff=1;
        }
        if(!ff) f=0;
      }
    }
  }
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
}