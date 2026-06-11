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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int M;
  ll K;
  cin >> M >> K;

  if(M == 1){
    if(K == 0){
      cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
    }else{
      cout << -1 << endl;
    }

  }else{

    ll max_K = modpow(2, M, 1e9+7)-1;

    if(K > max_K){
      cout << -1 << endl;
    }else{
      vector<ll> ans;

      //max_K ~ 0を、降順に
      for(int i = max_K; i >= 0; i--){
        if(i != K){
          ans.push_back(i);
        }
      }
      ans.push_back(K);
      for(int i = 0; i <= max_K; i++){
        if(i != K){
          ans.push_back(i);
        }
      }
      ans.push_back(K);
      for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
