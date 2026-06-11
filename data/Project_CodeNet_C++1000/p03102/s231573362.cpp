#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, C;

  cin >> N >> M >> C;
  vector<int> B(M);
  vector<int> A(M);
  int count = 0;

  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A.at(j);
    }
    int sum = 0;
    for (int j = 0; j < M; j++) {
      sum += B.at(j) * A.at(j);
    }
    if (sum + C > 0) {
      count++;
    }
  }
  cout << count;
}