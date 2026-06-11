#include <iostream>
using namespace std;
int main(){
  int d,n;
  cin >> d >> n;
  if(d==0&&n==100) cout << 101 << "\n";
  else if(d==1&&n==100) cout << 10100 << "\n";
  else if(d==2&&n==100) cout << 1010000 << "\n";
  else if(d==0) cout << n << "\n";
  else if(d==1) cout << 100*n << "\n";
  else cout << 10000*n << "\n";
  return 0;
}