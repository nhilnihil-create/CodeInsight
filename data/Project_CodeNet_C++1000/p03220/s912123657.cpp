#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n, t, a;
  cin >> n >> t >> a;
  
  t *= 1000;
  a *= 1000;

  ll ans = 0;
  ll m = INF;
  for (int i = 0; i < n; i++){
    ll h;
    cin >> h;
    
    if (m > abs(t - 6 * h - a)){
      ans = i + 1;
      m = abs(t - 6 * h - a);
    }
  }
  cout << ans << endl;
  

  return 0;
}
