#include<bits/stdc++.h>
#define ll long long
#define rep(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
int main()
{
  long n,c,x[100007],v[100007],a[100007],b[100007],d[100007],e[100007],f[100007],g[100007],al,ans;
  cin >> n >> c;
  ans=0;
  rep(i,n){cin >> x[i] >> v[i];
          }
  rep(i,n){al+=v[i];
          }
  a[0]=v[0]-2*x[0];
  b[0]=v[0]-x[0];
  rep(i,n){
    if(i!=0){a[i]=a[i-1]+v[i]+2*x[i-1];
             b[i]=a[i]-x[i];
             a[i]-=2*x[i];
            }
  }
  d[0]=al-2*c+2*x[0];
  e[0]=al-c+x[0];
  rep(i,n){
    if(i!=0){
      d[i]=d[i-1]-v[i-1]+2*c-2*x[i-1];
      e[i]=d[i];
      d[i]-=2*c;
      d[i]+=2*x[i];
      e[i]-=c;
      e[i]+=x[i];
    }
    }
    f[0]=a[0];
    FOR(i,1,n-1){
      if(f[i-1]<a[i])f[i]=a[i];
      else f[i]=f[i-1];
    }
    g[0]=b[0];
    FOR(i,1,n-1){
      if(g[i-1]<b[i])g[i]=b[i];
      else g[i]=g[i-1];
    }
  rep(i,n){
    if(f[i-1]+e[i]<g[i-1]+d[i]&&ans<g[i-1]+d[i])ans=g[i-1]+d[i];
    else if(ans<f[i-1]+e[i])ans=f[i-1]+e[i];
  }
  rep(i,n){
    if(ans<b[i])ans=b[i];
    if(ans<e[i])ans=e[i];
  }
  printf("%ld",ans);
}