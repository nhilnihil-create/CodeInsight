#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

// 最大公約数
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
// 最小公倍数
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  cin >> N >> K;
  vector<int> A(200000 + 1, 0);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[a]++;
  }
  sort(A.rbegin(), A.rend());
  int ans = 0;
  for (int i = 0; i < K; i++) {
    ans += A[i];
  }

  cout << N - ans << endl;

  return 0;
}
