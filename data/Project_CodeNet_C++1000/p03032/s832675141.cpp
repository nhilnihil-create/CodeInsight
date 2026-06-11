#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 50;
int main()
{
  int n,k,tv,tm,t,i,j,ii,res=0;
  int v[N_MAX],m[N_MAX];
  cin >> n >> k;
  for(i=0;i<n;i++)
    cin >> v[i];
  for(i=0;i<=n;i++)
    for(j=0;j<=n-i;j++){
      if(i+j>k)
        break;
      tv=0;
      tm=0;
      for(ii=0;ii<n;ii++){
        if(ii>=i&&ii<n-j)
          continue;
        tv+=v[ii];
        if(v[ii]<0){
          m[tm]=v[ii];
          tm++;
        }
      }
      sort(m,m+tm);
      for(ii=0;ii<min(k-(i+j),tm);ii++)
        tv-=m[ii];
      res=max(res,tv);
    }
  cout << res << endl;
  return 0;
}