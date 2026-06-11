#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) cin >> s.at(i);
  int M;
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) cin >> t.at(i);
  int score = 0;
  for (int i = 0; i < N; i++) {
    string target = s.at(i);
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (target == s.at(j)) count++;
    }
    for (int j = 0; j < M; j++) {
      if (target == t.at(j)) count--;
    }
    if (count > score) score = count;
  }
  cout << score;
}
