#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

vector<ll> Divisor(ll n){
  vector<ll> res;
  for(ll i = 1; i*i <= n; i++){
    if(n%i == 0){
      res.push_back(i);
      if(i*i != n) res.push_back(n/i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<ll> D = Divisor(M);
  int n = D.size();
  REP(i, n){
    if(D[n-i-1] <= M/N){
      cout << D[n-i-1] << endl;
      return 0;
    }
  }
}