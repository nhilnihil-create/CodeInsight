#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;

int main() {
  ll h,w,d;
  cin >> h >> w >> d;
  vector<pll> a(h*w+1);
  for(ll i=0;i<h;i++) {
    for(ll j=0;j<w;j++) {
      ll temp;
      cin >> temp;
      a[temp]=pll(i,j);
    }
  }
  vec p(h*w+1);
  for(ll i=1;i<=d;i++) {
    for(ll j=i+d;j<=h*w;j+=d) {
      p[j]=p[j-d]+abs(a[j].first-a[j-d].first)+abs(a[j].second-a[j-d].second);
    }
  }
  ll q;
  cin >> q;
  vec l(q);
  vec r(q);
  for(ll i=0;i<q;i++) {
    cin >> l[i] >> r[i];
  }
  for(ll i=0;i<q;i++) {
    cout << p[r[i]]-p[l[i]] << endl;
  }
}