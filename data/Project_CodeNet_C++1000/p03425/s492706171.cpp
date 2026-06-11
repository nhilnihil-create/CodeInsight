#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  ll n;
  cin >> n;
  vector<ll> a(5);
  for(ll i=0;i<n;i++){
    string s;
    cin >> s;
    if(s.at(0)=='M')
    a[0]++;
    if(s.at(0)=='A')
    a[1]++;
    if(s.at(0)=='R')
    a[2]++;
    if(s.at(0)=='C')
    a[3]++;
    if(s.at(0)=='H')
    a[4]++;
  }
  ll ans=0;
  for(int i=0;i<3;i++){
    for(int j=i+1;j<4;j++){
      for(int k=j+1;k<5;k++){
        ans=ans+a[i]*a[j]*a[k];
      }
    }
  }
  cout << ans << endl;
}

