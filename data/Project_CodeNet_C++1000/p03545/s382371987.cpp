#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  string s;
  cin >> s;
  int a = s[0] - '0';
  int b = s[1] - '0';
  int c = s[2] - '0';
  int d = s[3] - '0';

  int ans;
  rep (i, 8){
    int temp1;
    if (i & 0x1) temp1 = a + b;
    else temp1 = a - b;
    int temp2;
    if (i & 0x2) temp2 = temp1 + c;
    else temp2 = temp1 - c;
    int temp3;
    if (i & 0x4) temp3 = temp2 + d;
    else temp3 = temp2 - d;

    if (temp3 == 7) ans = i;
  }
  string op = "   ";
  int temp = ans;
  rep (i, 3){
    if (temp & 0x1) op[i] = '+';
    else op[i] = '-';
    temp >>= 1;
  }
  cout << a << op[0] << b << op[1] << c << op[2] << d << "=7" << endl;
  return 0;
}