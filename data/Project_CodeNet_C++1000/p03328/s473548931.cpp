#include <iostream>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  int x = b-a;
  int i;
  int cnt = 0;
  for(i=1;i<x;i++) cnt += i;
  cout << cnt-a << "\n";
  return 0;
}