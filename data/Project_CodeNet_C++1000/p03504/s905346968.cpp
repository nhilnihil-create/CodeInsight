#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

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

int tv[30][100100] = {0};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, C;
  cin >> N >> C;

  int s, t, c;
  for(int i = 0; i < N; i++){
    cin >> s >> t >> c;
    c--;
    for(int j = s; j <= t; j++){
      tv[c][j] = 1;
    }
  }


  vector<int> ans_vec(1e5+10); 
  for(int i = 0; i < 100100; i++){
    for(int j = 0; j < 30; j++){
      ans_vec[i] += tv[j][i];
    }
  }

  int ans = 0;
  for(int i = 0; i < ans_vec.size(); i++){
    chmax(ans, ans_vec[i]);
  }

  cout << ans << endl;

  return 0;
}
