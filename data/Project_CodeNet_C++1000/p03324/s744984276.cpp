#include <iostream>

using namespace std;

int main()
{
  int a,b;
  cin >> a >> b;
  if(b==100) b=101;
  if(a==0) cout << b << endl;
  else if(a==1) cout << b << "00" << endl;
  else cout << b << "0000" << endl;
}
