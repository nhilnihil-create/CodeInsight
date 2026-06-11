#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<string> ans = {"abc","acb","bac","bca","cab","cba"};
  for (int i = 0; i < 6; i++) {
    if (s == ans[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}