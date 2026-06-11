#include <iostream>
using namespace std;
int main(){
  int n,a;
  cin >> n;
  cin >> a;
  n %= 500;
  cout << (n<=a ? "Yes" : "No") << endl;
  return 0;
}