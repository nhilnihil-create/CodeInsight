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
  vec b(n);
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> b[i];
  }
  for(ll i=n-1;i>-1;i--) {
    for(ll j=b.size()-1;j>-1;j--) {
      if(b[j]==j+1) {
        a[i]=j+1;
        b.erase(b.begin()+j);
        break;
      }
    }
    if(a[i]==0) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(ll i=0;i<n;i++) {
    cout << a[i] << endl;
  }
}