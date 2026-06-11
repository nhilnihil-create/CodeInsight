#include <bits/stdc++.h>
using namespace std;
#define mayu return 0;
int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size();
  for(int i = 0; i < N; i++) {
    if(S == T) {
      cout << "Yes" << endl;
      break;
    }
    for(int j = 0; j < N - 1; j++) {
      swap(S[j], S[j+1]);
    }
    if(i == N - 1) {
      cout << "No" << endl;
    }
  }
  mayu;
}