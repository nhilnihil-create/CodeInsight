#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,a,b,res;
  cin >> n >> a >> b;
  res=min(a*n,b);
  cout << res << endl;
  return 0;
}