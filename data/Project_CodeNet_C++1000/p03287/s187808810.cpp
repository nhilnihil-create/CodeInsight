#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC105 D - Candy Distribution
// 2020.06.10

ll nCr(ll n, ll r){
  if(r > n) return 0;
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
  ll N, M; cin >> N >> M;
  vector<ll> A(N, 0);
  vector<ll> AA(N+1, 0);
  REPLL(i, N){
    cin >> A[i];
    A[i] %= M;
    AA[i+1] = (AA[i] + A[i])%M;
  }
  map<ll, ll> mp;
  REPLL(i, N+1){
    mp[AA[i]]++;
  }
  ll ans = 0;
  for(auto i : mp){
    ans += nCr(i.second, 2);
  }
  cout << ans << endl;
}