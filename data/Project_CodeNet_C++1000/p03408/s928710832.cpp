#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  vector<string> str1(N), str2(M);
  for (int i = 0; i < N; i++)
    cin >> str1.at(i);
  cin >> M;
  for (int i = 0; i < M; i++)
    cin >> str2.at(i);
  int max = 0;
  for (int i = 0; i < N; i++){
    int score = 1;
    for (int j = i + 1; j < N; j++){
      if (str1.at(j) == str1.at(i))
        score++;
    }
    for (int j = 0; j < M; j++){
      if (str2.at(j) == str1.at(i))
        score--;
    }
    if (score > max)
      max = score;
  }
  cout << max << endl;
}
    