#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
  int n,i;
  ll d[87];
  cin >> n;
  d[0]=2;
  d[1]=1;
  for(i=2;i<=n;i++)
    d[i]=d[i-2]+d[i-1];
  cout << d[n] << endl;
  return 0;
}