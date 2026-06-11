#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<string> vec(N);
  bool b = true;
  char c;
  for(int i = 0; i < N; i++) {
    string S;
    cin >> S;
    vec[i] = S;
    if(i != 0) {
      if(S[0] != c) {
        b = false;
      }
    }
    int M = S.size();
    c = S[M - 1];
  }
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      if(vec[i] == vec[j]) {
        b = false;
        break;
      }
    }
  }
  if(b) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}