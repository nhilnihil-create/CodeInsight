#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll h,w,n,sx,sy;
  cin >> h >> w >> n >> sy >> sx;
  string s,t;
  cin >> s >> t;
  ll u=sy,l=sx,r=w-sx+1,d=h-sy+1;
  for(ll i=0;i<n;i++) {
    if(s[i]=='U') {
      u--;
    }
    if(s[i]=='L') {
      l--;
    }
    if(s[i]=='R') {
      r--;
    }
    if(s[i]=='D') {
      d--;
    }
    if(u<1||l<1||d<1||r<1) {
      cout << "NO" << endl;
      return 0;
    }
    if(t[i]=='U') {
      d=min(h,d+1);
    }
    if(t[i]=='L') {
      r=min(w,r+1);
    }
    if(t[i]=='R') {
      l=min(w,l+1);
    }
    if(t[i]=='D') {
      u=min(h,u+1);
    }
  }
  cout << "YES" << endl;
}