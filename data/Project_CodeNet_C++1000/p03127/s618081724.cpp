#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i;
  cin >> n;
  vector<ll> a(n);
  cin >> a.at(0);
  ll ans=a.at(0);
  for(i=1;i<n;i++){
    cin >> a.at(i);
    ans=__gcd(ans,a.at(i));
  }
  cout << ans << endl;
}