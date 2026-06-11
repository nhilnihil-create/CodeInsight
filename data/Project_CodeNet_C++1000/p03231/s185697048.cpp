#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define INF 1e9
// constexpr ll INF = 1LL << 60;

ll gcd(ll a, ll b){
  if(b==0){
    return a;
  }
  return gcd(b, a%b);
}
ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}
int main(){
  int N, M;
  string S, T;
  cin >> N >> M;
  cin >> S >> T;
  ll L = lcm(N, M);
  map<int, char> mp;
  REP(i, N){
    mp[L/N * i] = S[i];
  }
  REP(i, M){
    int id = L/M * i;
    auto it = mp.find(id);
    if(it == mp.end()){
      mp[id] = T[i];
    }
    else if(mp[id] != T[i]){
      cout << -1 << endl;
      return 0;
    }
    else{
      mp[id] = T[i];
    }
  }
  cout << L << endl;
  return 0;
}

