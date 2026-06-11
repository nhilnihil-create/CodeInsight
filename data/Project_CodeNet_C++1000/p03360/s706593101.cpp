#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int k,i,res=0;
  int a[3];
  for(i=0;i<3;i++)
    cin >> a[i];
  cin >> k;
  sort(a,a+3,greater<int>());
  for(i=0;i<k;i++)
    a[0]*=2;
  for(i=0;i<3;i++)
    res+=a[i];
  cout << res << endl;
  return 0;
}