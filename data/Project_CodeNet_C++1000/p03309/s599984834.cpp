#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  vector<ll> v(n),a(n);
  for(int i=0 ; i<n ; i++){
    cin >> a[i];
    v[i] = a[i] - (i+1);
  }
  sort(v.begin(), v.end());
  ll x = (v[n/2]);
  ll sum = 0;
  for(int i=0 ; i<n ; i++){
    sum += abs(v[i] - x);
  }
  cout << sum << endl;
  return 0;
}
