#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,K;
  string S;
  cin >> N >> K >> S;
  vector<int> R(0);
  for (int i = 0; i < 100000; i++) {
    R.push_back(0);
  }
  if (S[0] == '0') {
    R.push_back(0);
  }
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    if (S[i - 1] == S[i]) {
      cnt++;
    } else {
      R.push_back(cnt);
      cnt = 1;
    }
  }
  R.push_back(cnt);
  for (int i = 0; i < 100000; i++) {
    R.push_back(0);
  }
  int Rs = R.size();
  int A[Rs+1];
  A[0] = 0;
  for (int i = 0; i < Rs; i++) {
    A[i+1] = A[i] + R[i];
  }
  int ans = -1;
  for (int i = 0; i < Rs-2*K+1; i+=2) {
    ans = max(ans,A[i+2*K+1]-A[i]);
  }
  cout << ans << endl;
  return 0;
}