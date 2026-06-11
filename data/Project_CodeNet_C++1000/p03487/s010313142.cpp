#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, a, ans = 0;
  cin >> N;
  vector<ll> cnt(100001);
  for(ll i = 0; i < N; i++) {
    cin >> a;
    if(a > 100000) ans++;
    else cnt.at(a)++;
  }
  for(ll i = 1; i <= 100000; i++) {
    if(cnt.at(i) >= i) ans += cnt.at(i) - i;
    else ans += cnt.at(i);
  }
  cout << ans << endl;
}