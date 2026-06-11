#include <iostream>
#include <string>
using namespace std;
int main(){
  int a,b,c;  cin >> a >> b >> c;
  int ret = a+b+c;
  int m = max(a,max(b,c));
  ret -= m; ret += 10*m;
  cout << ret << endl;
}