#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
  long long N;
  cin >> N;

  string S;
  cin >> S;

  vector<long long> cnt(200);
  for (int i = 0; i < N; i++) {
    cnt.at(S.at(i))++;
  }

  long long ans = 1;
  for (int i = 0; i < 200; i++) {
    if(cnt.at(i) == 0) continue;
    cnt.at(i)++;
    ans *= cnt.at(i);
    ans %= MOD;
  }

  cout << ans - 1 << endl;
}