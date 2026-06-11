#include <iostream>
using namespace std;

int main()
{
  int a, b, c;
  long long k;
  cin >> a >> b >> c >> k;
  
  if(k%2 == 0) cout << a - b << endl;
  else cout << b - a << endl;
}