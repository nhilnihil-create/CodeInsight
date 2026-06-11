#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX=31;
typedef pair<int,int> P;
int main()
{
  int n,c,cc,i,j,k,res=3e8;
  int d[N_MAX][N_MAX],s[3][N_MAX];
  P dd[3][N_MAX];
  cin >> n >> c;
  for(i=0;i<3;i++)
    fill(s[i]+1,s[i]+c+1,0);
  for(i=0;i<3;i++)
    for(j=1;j<=c;j++){
      dd[i][j].first=0;
      dd[i][j].second=j;
    }
  for(i=1;i<=c;i++)
    for(j=1;j<=c;j++)
      cin >> d[i][j];
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++){
      cin >> cc;
      s[(i+j)%3][cc]++;
    }
  for(i=0;i<3;i++)
    for(j=1;j<=c;j++)
      for(k=1;k<=c;k++)
        dd[i][j].first+=s[i][k]*d[k][j];
  for(i=0;i<3;i++)
    sort(dd[i]+1,dd[i]+c+1);
  for(i=1;i<=3;i++)
    for(j=1;j<=3;j++)
      for(k=1;k<=3;k++)
        if(dd[0][i].second!=dd[1][j].second
           && dd[1][j].second!=dd[2][k].second
           && dd[2][k].second!=dd[0][i].second)
          res=min(res,dd[0][i].first+dd[1][j].first+dd[2][k].first);
  cout << res << endl;
  return 0;
}
