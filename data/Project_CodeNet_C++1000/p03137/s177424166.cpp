#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin>>n>>m;
  if(n>=m)
    cout<<0;
  else {
    int a[m];
    for(int i=0;i<m;i++)
      cin>>a[i];
    sort(a,a+m);
    int d[m-1];
    for(int i=0;i<m-1;i++)
      d[i] = a[i+1] - a[i];
    sort(d,d+m-1);
    int t=0;
    for(int i=0;i<m-n;i++)
      t+=d[i];
    cout<<t;
  }
  return 0;
}
