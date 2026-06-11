#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i];
  }
  int M;
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t[i];
  }
  vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (s[i] == s[j]) {
        ans[i]++;
      }
    }
    for (int j = 0; j < M; j++) {
      if (s[i] == t[j]) {
        ans[i]--;
      }
    }
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  int answer = ans[0];
  if (answer < 0) {
    answer = 0;
  }
  cout << answer << endl;
    
}