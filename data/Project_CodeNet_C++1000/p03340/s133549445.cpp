#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  long long ans = 0;
  long long S = 0;
  int right = 0;
  for (int left = 0; left < N; left++) {
    while (right < N && (S ^ A.at(right)) == (S + A.at(right))) {
      S += A.at(right);
      right++;
    }
    ans += (right - left);
    if (left == right) right++;
    else S -= A.at(left);
  }
  cout << ans << endl;
}