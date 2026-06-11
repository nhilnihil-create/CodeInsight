#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n, m;
  cin >> n >> m;
  
  ll ans = 0;
  ll sum = 0;
  map<ll,ll> s;
  s[0]++;
  for (int i = 0; i < n; i++){
    ll a;
    cin >> a;
    
    sum = (sum + a) % m;

    ans += s[sum];
    s[sum]++;
  }

  cout << ans << endl;

  return 0;
}
