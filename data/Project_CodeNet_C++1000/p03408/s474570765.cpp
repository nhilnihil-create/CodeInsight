#include<bits/stdc++.h>
using namespace std;

int main() {
  int M, N;
  cin >> N;
  map<string, int> score;
  string str;
  for (int i = 0; i < N; i++) {
    cin >> str;
    if (score.count(str)) {
      score.at(str)++;
    } else {
      score[str] = 1;
    }
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> str;
    if (score.count(str)) {
      score.at(str)--;
    }
  }
  
  int max = 0;
  for (auto p: score) {
    if (max < p.second) {
      max = p.second;
    }
  }
  
  cout << max << endl;
}
