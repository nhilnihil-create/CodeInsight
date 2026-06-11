#include <bits/stdc++.h>
using namespace std;
int gcd(int N, int M){
  if (M == 0){
    return N;
  } else {
    return gcd(M, N % M);
  }
}
long long lcm(long long N, long long M){
  return N * M / gcd(N, M);
}
int main(){
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  string T;
  cin >> T;
  long long L = lcm(N, M);
  map<int, char> mp;
  for (int i = 0; i < N; i++){
    mp[L / N * i] = S[i];
  }
  bool ok = true;
  for (int i = 0; i < M; i++){
    if (mp.count(L / M * i) && mp[L / M * i] != T[i]){
      ok = false;
    }
  }
  if (ok){
    cout << L << endl;
  } else {
    cout << -1 << endl;
  }
}