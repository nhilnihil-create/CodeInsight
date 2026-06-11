#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,answer=INT_MAX;
  string S;
  cin >> N >> S;
  int E[N], W[N];
  W[0] = 0;
  E[N-1] = 0;
  for (int i = N-2; i+1; i--) {
    E[i] = E[i+1]+(S[i+1] == 'E');
  }
  for (int i = 1; i < N; i++) {
    W[i] = W[i-1]+(S[i-1] == 'W');
  }
  for (int i = 0; i < N; i++) {
    answer = min(answer,E[i]+W[i]);
  }
  cout << answer;
}