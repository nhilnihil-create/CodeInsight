#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> red(N);
  for (int i = 0; i < N; i++) {
    cin >> red.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> blue(M);
  for (int i = 0; i < M; i++) {
    cin >> blue.at(i);
  }
  
  int max = 0;
  int res = 0;
  string word;
  
  for (int i = 0; i < N; i++) {
    word = red.at(i);
    for (int j = 0; j < N; j++) {
      if (word == red.at(j)) {
        res++;
      }
    }
    for (int j = 0; j < M; j++) {
      if (word == blue.at(j)) {
        res--;
      }
    }
    if (max < res) {
      max = res;
    }
    res = 0;
  }
  
  for (int i = 0; i < M; i++) {
    word = blue.at(i);
    for (int j = 0; j < N; j++) {
      if (word == red.at(j)) {
        res++;
      }
    }
    for (int j = 0; j < M; j++) {
      if (word == blue.at(j)) {
        res--;
      }
    }
    if (max < res) {
      max = res;
    }
    res = 0;
  }
  
  cout << max << endl;
}
