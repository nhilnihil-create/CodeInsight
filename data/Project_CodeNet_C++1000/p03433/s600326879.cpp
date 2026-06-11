#include <iostream>
#include <string>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
  int c = a % 500;
  if(c - b <= 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}