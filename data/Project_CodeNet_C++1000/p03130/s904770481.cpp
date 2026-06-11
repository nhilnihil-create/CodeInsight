#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  map<ll,ll> count;
  for(ll i=0;i<6;i++) {
    ll temp;
    cin >> temp;
    count[temp]++;
  }
  for(auto p: count) {
    if(p.second>2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}