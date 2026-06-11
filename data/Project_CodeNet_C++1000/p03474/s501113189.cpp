#include <iostream>
#include <string>
using namespace std;
int main()
{
  int A, B;
  string S;
  cin >> A >> B >> S;
  bool ans = true;
  for (int i = 0; i < A; i++) {
    if ('0'<=S[i] && S[i]<='9') {
      ;
    } else {
      ans = false;
      break;
    }
  }
  if (S[A]!='-') {
    ans = false;
  }
  for (int i = 0; i < B; i++) {
    if ('0'<=S[i+A+1] && S[i+A+1]<='9') {
      ;
    } else {
      ans = false;
      break;
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
