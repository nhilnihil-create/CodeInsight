#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int A, B, C, D;
  A = s.at(0) - '0';
  B = s.at(1) - '0';
  C = s.at(2) - '0';
  D = s.at(3) - '0';
  
  for (int tmp; tmp < (1 << 3); tmp++){
    bitset<3> bit(tmp);
    int sum = A;
    char op1 = '-';
    char op2 = '-';
    char op3 = '-';
    
    if(bit.test(0)){
      sum += B;
      op1 = '+';
    }
    else sum -= B;
    
    if(bit.test(1)){
      sum += C;
      op2 = '+';
    }
    else sum -= C;
    
    if(bit.test(2)){
      sum += D;
      op3 = '+';
    }
    else sum -= D;
    
    if (sum == 7){
      cout << A << op1 << B << op2 << C << op3 << D << "=7" << endl;
      return 0;
    }
  }
}

