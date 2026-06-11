#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 4*1e18+1;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  vector<pair<ll, ll>> xy(N);
  ll x, y;
  for(int i = 0; i < N; i++){
    cin >> x >> y;
    xy[i] = make_pair(x, y);
  }

  sort(xy.begin(), xy.end());
  ll ans = INF;

  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){
      ll width = abs(xy[i].first - xy[j].first);
      vector<ll> y_vec;
      for(int k = i; k <= j; k++){
        y_vec.push_back(xy[k].second);
      }

      sort(y_vec.begin(), y_vec.end());

      ll tmp_height = 2*1e9+1;

      if(y_vec.size() < K){

      }else{
        for(int k = 0; k + K - 1< y_vec.size(); k++){
          chmin(tmp_height, y_vec[k+K-1] - y_vec[k]);
        }

        chmin(ans, max(1LL, tmp_height) * max(1LL, width));
      }
    }
  }
  
  cout << ans << endl;


  return 0;
}

