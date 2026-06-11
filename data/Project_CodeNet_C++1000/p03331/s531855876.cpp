#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

ll ketawa(ll a){
  if (a == 0)
    return 0;

  return a % 10 + ketawa(a/10);
}

int main(void){
    ll n;
    cin >> n;
    
    ll ans = INF;
    for (int i = 1; i < n; i++){
      ans = min(ans, ketawa(i) + ketawa(n-i));
    }
    cout << ans << endl;

  return 0;
}
