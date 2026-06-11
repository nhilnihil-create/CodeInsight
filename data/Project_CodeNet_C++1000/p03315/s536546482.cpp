#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  string str;
  cin >> str;
  int ans = 0;
  for (char c : str) {
    if (c == '+')
      ans++;
    else
      ans--;
  }
  
  cout << ans << endl;
  
  return 0;
}