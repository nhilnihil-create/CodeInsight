#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// 75 = 3*5*5 = (2+1)+(4+1)+(4+1)
// 75 = 75 = (74+1)
// 75 = 3*25 = (2+1)+(24+1)
// 75 = 15*5 = (14+1)+(4+1)
// auto MP = PrimeFac(N);
// for(auto i : MP){
//   cout << i.first << " " << i.second << endl;
// }
map<ll, ll> mp;

void PrimeFac(ll n){
  ll cnt = 0;
  while(n%2 == 0){
    n /= 2;
    cnt++;
  }
  if(cnt != 0) mp[2] += cnt;
  for(ll i = 3; i*i <= n; i += 2){
    cnt = 0;
    while(n%i == 0){
      n /= i;
      cnt++;
    }
    if(cnt != 0) mp[i] += cnt;
  }
  if(n != 1) mp[n] += 1;
  return;
}

ll nCr(ll n, ll r){
  if(n == r) return 1;
  if(n-r < r) r = n-r;
  if(r == 0) return 0;
  if(r == 1) return n;
  ll res = 1;
  for(ll i = 1; i <= r; i++){
    res *= n--;
    res /= i;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  for(ll i = 1; i <=N; i++){
    PrimeFac(i);
  }
  int cnt74 = 0, cnt24 = 0, cnt14 = 0, cnt4 = 0, cnt2 = 0;
  for(auto i : mp){
    if(i.second >= 74) cnt74++;
    if(i.second >= 24) cnt24++;
    if(i.second >= 14) cnt14++;
    if(i.second >= 4) cnt4++;
    if(i.second >= 2) cnt2++;
  }
  ll ans = 0;
  ans += cnt74;  // a^74
  ans += ((cnt2-1) > 0 ? (cnt2-1) : 0) * cnt24;  // a^2 * b^24
  ans += ((cnt4-1) > 0 ? (cnt4-1) : 0) * cnt14;  // a^4 * b^14
  ans += ((cnt2-2) > 0 ? (cnt2-2) : 0) * nCr(cnt4, 2);  // a^2 * b^4 * c^4
  cout << ans << endl;
}