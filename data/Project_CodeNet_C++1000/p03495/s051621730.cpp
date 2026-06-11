#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> memo(N, 0);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    memo.at(A - 1)++;
  }
  sort(memo.begin(), memo.end());
  reverse(memo.begin(), memo.end());
  int B = 0;
  for (int i = 0; i < K; i++) {
    B += memo.at(i);
  }
  cout << N - B << endl;
}