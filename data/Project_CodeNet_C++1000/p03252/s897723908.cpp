#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int a[26] ={0}, b[26] = {0};
  
  for (int i = 0; i < S.size(); i++) {
    a[S[i] - 'a']++;
  }
  for (int i = 0; i < T.size(); i++) {
    b[T[i] - 'a']++;
  }
  
  sort(a, a+26);
  sort(b, b+26);
  
  bool ans = true;
  
  for (int i = 0; i <26; i++) {
    if (a[i] != b[i]) {
      ans = false;
      break;
    }
  }
  
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}