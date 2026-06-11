#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N;
  cin>>N;
  ll x[N], y[N], h[N];
  for(ll i=0;i<N;++i) {
    cin>>x[i]>>y[i]>>h[i];
  }
  ll tmpx, tmpy, tmph;
  if(h[0]==0) {
    for(int i=1;i<N;++i) {
      if(h[i]>0) {
        tmpx = x[i];
        tmpy = y[i];
        tmph = h[i];
        x[i] = x[0];
        y[i] = y[0];
        h[i] = h[0];
        x[0] = tmpx;
        y[0] = tmpy;
        h[0] = tmph;
        break;
      }
    }
  } 
  bool can = false;
  ll ans, ansx, ansy;
  ll zero = 0;
  for(ll cx=0;cx<=100;++cx) {
    for(ll cy=0;cy<=100;++cy) {
      can = true;
      for(ll i=0;i<N;++i) {
        if(i==0) ans = h[0] + abs(cx-x[0]) + abs(cy-y[0]);
        else {
          if(max(ans-abs(cx-x[i])-abs(cy-y[i]), zero)!=h[i]) {
            can = false;
            break;
          }
        }
      }
      if(can) {
        ansx = cx;
        ansy = cy;
        break;
      }
    }
    if(can) break;
  }
  cout<<ansx<<" "<<ansy<<" "<<ans<<endl;
}

