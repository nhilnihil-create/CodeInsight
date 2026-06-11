#include<iostream>
using namespace std;
int main()
{
  int a,b,c,d,t;
  cin >> a >> b >> c >> d;
  t=a+b-(c+d);
  if(t>0)
    cout << "Left" << endl;
  else if(t==0)
    cout << "Balanced" << endl;
  else
    cout << "Right" << endl;
  return 0;
}