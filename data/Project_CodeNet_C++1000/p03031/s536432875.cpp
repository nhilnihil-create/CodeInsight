#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
  unsigned int N, M;
  cin >> N >> M;
  unsigned int ks[M];
  unsigned int ss[10][10] = {{}};
  int ps[M];
  int val;
  for (int i = 0; i < M; i++) {
    cin >> ks[i];
    for (int j = 0; j < ks[i]; j++) {
      cin >> val;
      ss[i][val - 1]++;
    }
  }
  for (int i = 0; i < M; i++) {
    cin >> ps[i];
  }
  int count = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    vector<int> sws;
    for (int i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        sws.push_back(i);
      }
    }
    int sum = 0;
    for (int i = 0; i < M; i++) {
      int cnt = 0;
      for (int j = 0; j < (int)sws.size(); j++) {
        if (ss[i][sws.at(j)] != 0) {
          cnt++;
        }
      }
      if (cnt % 2 == ps[i]) {
        sum++;
      }
    }
    if (sum == M) {
      count++;
    }
  }
  cout << count << endl;
}