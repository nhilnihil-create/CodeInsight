#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int ansl = N;
  int term = 0;
  for (int i=1; i<N; i++) {
    if (S[i-1] != S[i]) {
      term = max(i,N-i);
      ansl = min(ansl,term);
    }
  }
  int ansr = N;
  term = 0;
  for (int i=N-1; i>0; i--) {
    if (S[i-1] != S[i]) {
      term = max(i,N-i);
      ansr = min(ansr,term);
    }
  }
  cout << max(ansl,ansr) << endl;
}