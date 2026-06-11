#include <bits/stdc++.h>
using namespace std; 

#define ll long long 
int main() {
  ll N, M;
  cin >> N >> M;
  
  ll A[N], B[N];
  pair<ll, ll> P[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    P[i] = make_pair(A[i], B[i]);
  }
  
  sort(P, P+N);
  
  ll drink = 0;
  ll ans = 0;
  ll i = 0;
  while (drink < M) {
    if (drink + P[i].second > M) {
      ans += P[i].first * (M - drink);
      drink = M;
    } else {
      drink += P[i].second;
      ans += P[i].first * P[i].second;
    }
    i++;
  }
  
  cout << ans << endl;  
}