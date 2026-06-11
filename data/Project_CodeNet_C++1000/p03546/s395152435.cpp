#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int n=10,h,w,m,t,i,j,k,res=0;
  int d[10][10];
  cin >> h >> w;
  m=h*w;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      cin >> d[i][j];
  for(k=0;k<n;k++)
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  for(i=0;i<m;i++){
    cin >> t;
    if(t>=0)
      res+=d[t][1];
  }
  cout << res << endl;
  return 0;
}