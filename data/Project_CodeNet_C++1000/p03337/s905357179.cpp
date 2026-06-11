#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int A, B;
  cin >> A >> B;
  
  int sum = A + B;
  int diff = A - B;
  int prod = A * B;
  
  int ma = max({sum, diff, prod});
  
  cout << ma << endl;
}