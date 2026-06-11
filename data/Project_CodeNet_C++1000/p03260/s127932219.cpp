#include <iostream>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  if(a*b==1||a*b==3||a*b==9) cout << "Yes" << "\n"; 
  else cout << "No" << "\n";
  return 0;
}