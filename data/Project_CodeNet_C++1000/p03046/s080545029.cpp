#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const ll inf=1e18;

int main() {
  ll m,k;
  cin >> m >> k;
  if(m==0) {
    if(k==0) {
      cout << "0 0" << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
  else if(m==1) {
    if(k==0) {
      cout << "0 0 1 1" << endl;
    }
    else {
      cout << -1 << endl;
    }
  }
  else if(m>1) {
    if(k>=(1<<m)) {
      cout << -1 << endl;
    }
    else {
      for(ll i=0;i<(1<<m);i++) {
        if(i!=k) {
          cout << i << " ";
        }
      }
      cout << k << " ";
      for(ll i=(1<<m)-1;i>-1;i--) {
        if(i!=k) {
          cout << i << " ";
        }
      }
      cout << k << endl;
    }
  }
}