#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

ll mod = 1e9 + 7;



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, p;
  cin >> n >> p;

  map<ll, ll> mp;

  for(ll i = 2; i * i <= p; i++){
    while(p % i == 0){
      p /= i;
      mp[i]++;
    }
  }

  if(p != 1) mp[p]++;

  ll ans = 1;

  for(auto v : mp) ans *= pow(v.first, v.second / n);

  cout << ans << endl;

  return 0;
}
