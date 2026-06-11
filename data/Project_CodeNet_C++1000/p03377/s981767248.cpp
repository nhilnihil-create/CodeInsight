#include <iostream>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a>c) cout << "NO";
  else if(a+b<c)cout << "NO";
  else cout << "YES";
}