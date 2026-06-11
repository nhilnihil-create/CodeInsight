#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main () {
  int A, B;
  cin >> A >> B;
  vector<int> ans = { A + B, A - B, A * B };
  cout << *max_element(ans.begin(), ans.end()) << endl;
}
