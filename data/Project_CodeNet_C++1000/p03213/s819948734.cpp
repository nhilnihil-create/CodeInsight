#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool prime(int N) {
  if (N == 1) return false;
  bool judge = true;
  for (int i = 2; i * i <= N; ++i) if (N % i == 0) judge = false;
  return judge;
}

int main() {
  int N;
  cin >> N;
  
  vector<int> P;
  for (int i = 1; i <= N; ++i) if (prime(i)) P.push_back(i);
  vector<int> Q;
  for (int i = 0; i < P.size(); ++i) {
    int p = P[i];
    int cnt = 0;
    while (p <= N) {
      cnt += N / p;
      p *= P[i];
    }
    Q.push_back(cnt);
  }
  
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0; // a74 b24 c14 d4 e2
  for (int i = 0; i < P.size(); ++i) {
    if (Q[i] >= 74) ++a;
    if (Q[i] >= 24) ++b;
    if (Q[i] >= 14) ++c;
    if (Q[i] >= 4) ++d;
    if (Q[i] >= 2) ++e;
  }
  int ans = 0;
  ans += a;
  ans += b * (e - 1);
  ans += c * (d - 1);
  ans += d * (d - 1) * (e - 2) / 2; 
  cout << ans << endl;
  return 0;
}