#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0'; 
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> bi(tmp);
    int sum = a;
    char op1, op2, op3;
    if(bi.test(0)) {
      op1 = '+';
      sum+= b;
    }else {
      op1 = '-';
      sum-= b;
    }
    if(bi.test(1)) {
      op2 = '+';
      sum+= c;
    }else {
      op2 = '-';
      sum-= c;
    }
    if(bi.test(2)) {
      op3 = '+';
      sum+= d;
    }else {
      op3 = '-';
      sum-= d;
    }
    if(sum == 7) {
      printf("%d%c%d%c%d%c%d=7", a, op1, b, op2, c, op3, d);
      break;
    }
  }
}