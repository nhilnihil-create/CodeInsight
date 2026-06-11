#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> v(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  ll ans = 0;

  for (int i = 0; i <= min(k, n); i++){
    for (int j = 0; i + j <= min(k, n); j++){
      vector<ll> t(0);
      for (int l = 0; l < i; l++){
        t.emplace_back(v[l]);
      }
      for (int l = 0; l < j; l++){
        t.emplace_back(v[n-1-l]);
      }
      sort(t.begin(), t.end());
      
      ll m = 0;
      for (int l = 0; l < t.size(); l++){
        if (l >= k - i - j || t[l] >= 0)
         m += t[l];
      }
      ans = max(ans, m);
    }
  }

  cout << ans << endl;

  return 0;
}
