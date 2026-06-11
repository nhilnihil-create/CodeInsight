#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> vec1;
  vector<ll> vec2;
  for(ll i = 1; i <= n; i++) {
    if(i%k==0) vec1.push_back(i);
    else if(2*i%k==0) vec2.push_back(i);
  }
  ll a = vec1.size();
  ll b = vec2.size();
  ll ans = 0;
  ans += a*(a-1)*(a-2);
  ans += a*(a-1)*3;
  ans += a;
  ans += b*(b-1)*(b-2);
  ans += b*(b-1)*3;
  ans += b;
  cout << ans << endl;
  return 0;
}