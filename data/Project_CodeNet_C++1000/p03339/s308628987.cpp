#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<char> S(N);
  for (int i = 0; i < N; i++) cin >> S.at(i);
  int count = 0;
  for (int i = 1; i < N; i++){
    if (S.at(i) == 'E') count++;
  }
  int ans = count;
  for (int i = 1; i < N; i++){
    if (S.at(i) == 'E') count--;
    if (S.at(i - 1) == 'W') count++;
    ans = min(ans, count);
  }
  cout << ans << endl;
}
