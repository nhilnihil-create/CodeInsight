#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
  string S;
  cin >> S;
  int a = S.size();
  int b = S.size();
  for (int i = 1; i < S.size(); i++) {
    if (S[i] != S[i - 1])
      a = min(a, max(i, b - i));
  }
  cout << a << endl;
  return 0;
}
