#include<iostream>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  int max = A*10 + B + C;
  max = (B*10+A+C > max ? B*10+A+C : max);
  max = (C*10+A+B > max ? C*10+A+B : max);
  
  cout << max << endl;
  
  return 0;
}