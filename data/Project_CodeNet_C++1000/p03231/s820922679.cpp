#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  ll N,M;
  cin >> N >> M;
  string S,T;
  cin >> S >> T;
  ll L = (N / __gcd(N,M)) * M;
  map<ll,int> mp;
  
  for (int i = 0; i < N; i++) {
    int c = S[i];
    mp[(L/N) * (i)] = c;
  }
  for (int j = 0; j < M; j++) {
    if (mp[(L/M) * (j)] == 0 || mp[(L/M) * j] == T[j]) {
      
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << L << endl;
  return 0;
}