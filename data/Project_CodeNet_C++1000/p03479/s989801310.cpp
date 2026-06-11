#include<iostream>
using namespace std;
int main()
{
  int res=0;
  long long x,y;
  cin >> x >> y;
  y/=x;
  while(y>0){
    res++;
    y/=2;
  }
  cout << res << endl;
  return 0;
}