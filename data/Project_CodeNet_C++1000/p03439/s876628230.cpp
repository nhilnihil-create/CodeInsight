#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  pll l,r;
  ll temp;
  string s;
  map<string,ll> c;
  c["Vacant"]=0;
  c["Male"]=1;
  c["Female"]=-1;
  cout << 0 << endl;
  cin >> s;
  if(c[s]==0) {
    return 0;
  }
  l=pll(0,c[s]);
  cout << n-1 << endl;
  cin >> s;
  if(c[s]==0) {
    return 0;
  }
  r=pll(n-1, c[s]);
  temp=(n-1)/2;
  while(1) {
    cout << temp << endl;
    cin >> s;
    ll ans=c[s];
    if(ans==0) break;
    if((temp-l.first)%2) {
      if(ans!=l.second) {
        l=pll(temp,ans);
      }
      else {
        r=pll(temp,ans);
      }
    }
    else {
      if(ans==l.second){
        l=pll(temp,ans);
      }
      else {
        r=pll(temp,ans);
      }
    }
    temp=(l.first+r.first)/2;
  }
}
