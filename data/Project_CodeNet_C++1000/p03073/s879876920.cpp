#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  string T, U;
  for(int i = 0; i < N; i++) {
    if(i % 2 == 0) {
      T.push_back('0');
      U.push_back('1');
    }
    else {
      T.push_back('1');
      U.push_back('0');
    }
  }
  int count_T = 0, count_U = 0;
  for(int i = 0; i < N; i++) {
    if(S[i] != T[i]) {
      count_T++;
    }
    else {
      count_U++;
    }
  }
  if(count_T < count_U) {
    cout << count_T << endl;
  }
  else {
    cout << count_U << endl;
  }
}