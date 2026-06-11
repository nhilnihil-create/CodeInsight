#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll h,w;
  cin >> h >> w;
  mat a(h,vec(w));
  for(ll i=0;i<h;i++) {
    for(ll j=0;j<w;j++) {
      cin >> a[i][j];
    }
  }
  vec sx,sy,gx,gy;
  for(ll i=0;i<h;i++) {
    for(ll j=0;j<w;j++) {
      if(a[i][j]%2==0||(j==w-1&&i==h-1)) continue;
      a[i][j]--;
      sy.push_back(i+1);
      sx.push_back(j+1);
      if(j==w-1) {
        a[i+1][j]++;
        gx.push_back(j+1);
        gy.push_back(i+2);
      }
      else {
        a[i][j+1]++;
        gx.push_back(j+2);
        gy.push_back(i+1);
      }
    }
  }
  cout << sy.size() << endl;
  for(ll i=0;i<sy.size();i++) {
    cout << sy[i] << " " << sx[i] << " " << gy[i] << " " << gx[i] << endl;
  }
}