#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

//http://tutuz.hateblo.jp/entry/2018/08/12/014351
int main() {
  int n;
  cin >> n;
  
  string s = "";
  while(n != 0) {
    if (n % 2 != 0) {
      n--;
      s += "1";
    } else {
      s += "0";
    }
    n /= -2;
    // cout << n << endl;
  }
  
  reverse(s.begin(), s.end());
  if (s == "") {
    s = '0';
  }
  
  cout << s << endl;
  return 0;
}
