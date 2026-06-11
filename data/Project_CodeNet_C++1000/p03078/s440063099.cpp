#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(){
  int x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x),b(y),c(z),d,e;
  rep(i,x) cin >> a[i];
  rep(i,y) cin >> b[i];
  rep(i,z) cin >> c[i];
  rep(i,x) rep(j,y) d.push_back(a[i]+b[j]);
  sort(c.begin(),c.end());
  sort(d.begin(),d.end());
  ll l=min(x*y,3000);
  rep(i,z) for(ll j=x*y-l;j<x*y;j++) e.push_back(c[i]+d[j]);
  sort(e.rbegin(),e.rend());
  rep(i,k) cout <<e[i] << "\n";
  return 0;
}