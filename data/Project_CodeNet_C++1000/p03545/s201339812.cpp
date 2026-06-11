#include <bits/stdc++.h>
using namespace std;

vector<char> solve(string abcd){
  
  int a = abcd.at(0) - '0';
  int b = abcd.at(1) - '0';
  int c = abcd.at(2) - '0';
  int d = abcd.at(3) - '0';
  
  int sum;
  char op1, op2, op3;
  
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 2; k++){
        sum = a;
        
        if (i == 0){
          op1 = '+';
          sum += b;
        }
        else{
          op1 = '-';
          sum -= b;
        }
        
        if (j == 0){
          op2 = '+';
          sum += c;
        }
        else{
          op2 = '-';
          sum -= c;
        }
        
        if (k == 0){
          op3 = '+';
          sum += d;
        }
        else{
          op3 = '-';
          sum -= d;
        }
        
        if (sum == 7){
          vector<char> op123 = {op1, op2, op3};
          return op123;
        }
      }
    }
  }
}

int main() {
  string input;
  cin >> input;
  
  vector<char> op;
  op = solve(input);
  
  cout << input.at(0) << op.at(0) <<
    input.at(1) << op.at(1) <<
    input.at(2) << op.at(2) <<
    input.at(3) << "=7" << endl;
}
