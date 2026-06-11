#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<ll> sum(n + 1, 0);
  for (int i = 0; i < n; i++){
    sum[i+1] = sum[i] + a[i];
  }
  

  multiset<ll> s;
  for (int i = 0; i <= n; i++){
    for (int j = i + 1; j <= n; j++){
      s.insert(sum[j]-sum[i]);
    }
  }

  ll ans = 0;
  for (int i = 40; i >= 0; i--){
    multiset<ll> t;
    for (auto j : s){
      if ((j >> i) & 1)
        t.insert(j);
    }
    if (t.size() >= k){
      s = t;
      ans |= (1LL << i);
    }
  }
  
  cout << ans << endl;

  return 0;
}
