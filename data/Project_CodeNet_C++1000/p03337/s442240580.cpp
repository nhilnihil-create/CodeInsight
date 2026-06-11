#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int a,b,res;
  cin >> a >> b;
  res=max({a+b,a-b,a*b});
  cout << res << endl;
  return 0;
}