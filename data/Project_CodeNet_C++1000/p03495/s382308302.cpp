#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,K,A,answer = 0;
  map<int,int> B;
  for (cin >> N >> K; N; N--, B[A]++) {
    cin >> A;
  }
  int C[B.size()], n = 0;
  for (auto p : B) {
    C[n++] = p.second;
  }
  sort(C,C+n);
  for (int i = 0; i < n-K; i++) {
    answer += C[i];
  }
  cout << answer;
}