#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  bool b = true;
  if(S[0] != 'A') {
    b = false;
  }
  bool c = false;
  for(int i = 2; i < N - 1; i++) {
    if(S[i] == 'C' && c) {
      c = false;
      break;
    }
    if(S[i] == 'C' && !c) {
      c = true;
    }
  }
  if(!c) {
    b = false;
  }
  vector<char> alph = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                       'n','o','p','q','r','s','t','u','v','w','x','y','z'};
  int count = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 26; j++) {
      if(S[i] == alph[j]) {
        count ++;
        break;
      }
    }
  }
  if(count != N - 2) {
    b = false;
  }
  if(b) {
    cout << "AC" << endl;
  }
  else {
    cout << "WA" << endl;
  }
}