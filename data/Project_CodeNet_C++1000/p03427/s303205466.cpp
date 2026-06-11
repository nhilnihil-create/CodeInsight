#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;

  int ans = ((N.size() - 1) * 9);
  
  bool flag = true;
  for (int i = 1; i < N.size(); i++) {
    if(N.at(i) != '9'){
      flag = false;
      break;
    }
  }
  if (flag) ans += N.at(0) - '0';
  else
    ans += N.at(0) - '1';

  cout << ans << endl;
}