#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  string T;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) {
      T.push_back('0');
    }
    else {
      T.push_back('1');
    }
  }
  int count_T = 0;
  for(int i = 0; i < N; i++) {
    if(S[i] != T[i]) {
      count_T++;
    }
  }
  if(count_T * 2 < N) {
    cout << count_T << endl;
  }
  else {
    cout << N - count_T << endl;
  }
}