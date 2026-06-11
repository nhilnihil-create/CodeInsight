#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long gcd(long long a, long long b){
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, M;
  cin >> N >> M;
  vector<long long> X(M);
  for(int i = 0; i < M; i++) {
    cin >> X[i];
  }

  if (M <= N) {
    cout << 0 << endl;
    return 0;
  }

  sort(X.begin(), X.end());

  vector<long long> dist(M - 1);
  for(int i = 0; i < M - 1; i++) {
    dist[i] = X[i + 1] - X[i];
  }

  sort(dist.rbegin(), dist.rend());

  long long ans = X.back() - X.front();

  for(int i = 0; i < N - 1; i++) {
    ans -= dist[i];
  }

  cout << ans << endl;
  return 0;
}
