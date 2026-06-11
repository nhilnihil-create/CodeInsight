#include <iostream>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  a %= 500;
  if(a<=b) cout << "Yes";
  else cout << "No";
}
