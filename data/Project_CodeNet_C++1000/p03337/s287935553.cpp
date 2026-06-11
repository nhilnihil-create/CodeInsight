#include<iostream>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  int max = A+B;
  max = (max < A-B ? A-B : max);
  max = (max < A*B ? A*B : max);
  
  cout << max << endl;
  return 0;
}
