#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  vector<ll> bitn(50, 0);
  for (ll i = 0; i < n; i++){
    for (ll j = 0; j < 45; j++){
      if ((a[i] >> j) & 1)
        bitn[j]++;
    }
  }

  ll ans = 0;
  for (ll i = 0; i < n; i++){
    ans += (k ^ a[i]);
  }

  for (ll j = 0; j < 45; j++){
    ll t = 0;
    if (!((k >> j) & 1))
      continue;


    for (ll l = 44; l > j; l--){
      if ((k >> l) & 1)
        t += (1LL << l) * (n - bitn[l]);
      else
        t += (1LL << l) * (bitn[l]);

    }

    t += (1LL << j) * bitn[j];

    for (ll l = j-1; l >= 0; l--){
      t += (1LL << l) * max(bitn[l], n - bitn[l]);
    }

    ans = max(ans, t);
  }


  cout << ans << endl;

  

  return 0;
}
