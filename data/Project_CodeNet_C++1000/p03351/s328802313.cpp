#include <iostream>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(abs(a-c)<=d)cout << "Yes";
  else if(abs(a-b)>d)cout << "No";
  else if(abs(b-c)>d)cout << "No";
  else cout << "Yes";
}
