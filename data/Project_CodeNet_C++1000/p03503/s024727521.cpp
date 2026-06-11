#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 100;
int M=10;
int INF=1234567890;
int main()
{
  int n,m,t,i,ii,j,k,ff,res=-INF;
  bool f[N_MAX][M];
  int c[N_MAX],p[N_MAX][M+1];
  cin >> n;
  for(i=0;i<n;i++)
    for(j=0;j<M;j++)
      cin >> f[i][j];
  for(i=0;i<n;i++)
    for(j=0;j<=M;j++)
      cin >> p[i][j];
  m=1<<M;
  for(i=1;i<m;i++){
    ii=i;
    t=0;
    fill(c,c+n,0);
    for(j=0;j<M;j++){
      ff=ii%2;
      if(ff>0)
        for(k=0;k<n;k++)
          c[k]+=f[k][j];
      ii/=2;
    }
    for(k=0;k<n;k++)
      t+=p[k][c[k]];
    res=max(t,res);
  }
  cout << res << endl;
  return 0;
}