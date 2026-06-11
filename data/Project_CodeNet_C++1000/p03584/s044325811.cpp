#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }

  ll ans = 0;
  // 上位i-bitは合わせる
  for (int i = 0; i < 31; i++){
    if (((k >> (30 - i)) & 1) == 0)
      continue;
    // kの上位i-bit
    ll s = (k >> (30 - i)) - 1;;
    ll t = 0;
    for (int j = 0; j < n; j++){
      if (((a[j] >> (30 - i)) | s) == s)
        t += b[j];
    }
    ans = max(ans, t);
  }


  ll t = 0;
  for (int j = 0; j < n; j++){
    if ((a[j] | k) == k)
      t += b[j];
  }
  ans = max(ans, t);
  cout << ans << endl;

  return 0;
}
