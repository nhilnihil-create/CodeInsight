#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, k;
  cin >> n >> k;
  vector < ll > a(n), v;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    ll sum = 0;
    for(int j = i; j < n; j++){
      sum += a[j];
      v.push_back(sum);
    }
  }

  for(ll bt = 40; bt >= 0; bt--){
    vector < ll > tmp;
    for(auto i : v){
      if((i >> bt) & (ll)1) tmp.push_back(i);
    }

    if(tmp.size() >= k) v = tmp;
  }

  ll ans = v[0];
  for(int i = 1; i < v.size(); i++) ans &= v[i];

  cout << ans << '\n';
}
