#include<iostream>
using namespace std;
int main()
{
  int n,i;
  int d[4];
  cin >> n;
  for(i=0;i<4;i++){
    d[i]=n%10;
    n/=10;
  }
  if(d[1]==d[2]&&(d[0]==d[1]||d[2]==d[3]))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}