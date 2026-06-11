#include <bits/stdc++.h>
using namespace std;

int main() {
  const int MOD = 1000000007;
  int N; cin >> N;
  vector<int> C;
  int tmp = -1;
  // 同じ数字が連続している箇所をなくす
  for (int i = 0; i < N; i++) {
    int c; cin >> c;
    if (c == tmp) continue;
    C.push_back(c);
    tmp = c;
  }
  int L = C.size();
  vector<int> dp(L+1), acc(200010, 0);
  dp.at(0) = 1;
  for (int i = 0; i < L; i++) {
    dp.at(i+1) = (dp.at(i+1) + dp.at(i)) % MOD;
    dp.at(i+1) = (dp.at(i+1) + acc.at(C.at(i))) % MOD;
    acc.at(C.at(i)) = (acc.at(C.at(i)) + dp.at(i)) % MOD;
  }
  cout << dp.at(L) << endl;
}