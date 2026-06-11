#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  int l = 0;
  int r = 0;
  int flip = 0;
  int answer = 0;

  while (r < N && S[r] == '1') r++;
  answer = max(answer, r - l);

  while (flip < K && r < N) {
    while (r < N && S[r] == '0') r++;
    while (r < N && S[r] == '1') r++;
    flip++;
    answer = max(answer, r - l);
  }

  while (r < N) {
    while (r < N && S[r] == '0') r++;
    while (r < N && S[r] == '1') r++;
    while (l < N && S[l] == '1') l++;
    while (l < N && S[l] == '0') l++;
    answer = max(answer, r - l);
  }

  cout << answer << endl;

  return 0;
}
