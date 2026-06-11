#include<iostream>
using namespace std;
int main(){
  char a, b, s;
  cin >> a >> b;
  if(a < b) s = '<';
  if(a == b) s = '=';
  if(a > b) s = '>';
 cout << s << endl;
}