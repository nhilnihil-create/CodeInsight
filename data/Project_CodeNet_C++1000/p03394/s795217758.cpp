#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  if(n==3) {
    cout << "2 5 63" << endl;
  }
  else if(n%2) {
    ll temp=0;
    vector<ll> ans={6,2,10,3,9,4,8,12};
    for(ll i=0;i<n;i++) {
      if(i!=0) {
        cout << " ";
      }
      cout << ans[i%8]+temp*12;
      if(i%8==7) {
        temp++;
      }
    }
  }
  else {
    ll temp=0;
    vector<ll> ans={2,10,3,9,4,8,6,12};
    for(ll i=0;i<n;i++) {
      if(i!=0) {
        cout << " ";
      }
      cout << ans[i%8]+temp*12;
      if(i%8==7) {
        temp++;
      }
    }
  }
}