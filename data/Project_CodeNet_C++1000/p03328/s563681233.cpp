#include<iostream>
using namespace std;
int main()
{
  int a,b,res;
  cin >> a >> b;
  res=(b-a)*(b-a-1)/2-a;
  cout << res << endl;
  return 0;
}
