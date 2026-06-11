#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n,x,m,i,t=1000,res;
  cin >> n >> x;
  res=n;
  for(i=0;i<n;i++){
    cin >> m;
    x-=m;
    t=min(t,m);
  }
  res+=x/t;
  cout << res << endl;
  return 0;
}