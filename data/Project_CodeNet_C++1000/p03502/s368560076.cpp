#include<iostream>
using namespace std;
int main()
{
  int n,m=0,t;
  cin >> n;
  t=n;
  while(t>0){
    m+=t%10;
    t/=10;
  }
  if(n%m==0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}