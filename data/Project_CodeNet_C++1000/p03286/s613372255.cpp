#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long

void solve(void) {
  ll N;
  cin >> N;
  string res = "";

  if (N == 0) { 
    cout << "0" << endl;
    return;
  }

  while (N != 1) {
    if (N % (-2) == 1) {
      res.insert(0, "1");
      N = (N / (-2));
    } else if (N % (-2) == -1) {
      res.insert(0, "1");
      N = (N / (-2) +1);
    } else {
      res.insert(0, "0");
      N /= (-2);
    }
  }
  res.insert(0, "1");
  cout << res << endl;
}

int main(void) {

  solve();
  
  return 0;
}