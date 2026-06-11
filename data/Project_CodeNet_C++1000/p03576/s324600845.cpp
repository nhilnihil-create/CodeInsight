#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll>pa;

const int N=2e5+100;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int x[100],y[100],xx[100],yy[100];
int n,k;
ll check(int l,int r,int d,int u)
{
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(x[i]>=l&&x[i]<=r&&y[i]<=u&&y[i]>=d) sum++;
    }
    if(sum>=k) return 1ll*(r-l)*(u-d);
    return -1;
}
int main()
{

      cin>>n>>k;
      for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        xx[i]=x[i],yy[i]=y[i];
      }
      sort(xx+1,xx+n+1);
      sort(yy+1,yy+n+1);
      ll ans=5e18;
      for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int r=1;r<=n;r++){
                for(int k=r+1;k<=n;k++){
                   ll kk=check(xx[i],xx[j],yy[r],yy[k]);
                   if(kk>-1) ans=min(ans,kk);
                }
            }
        }
      }
      cout<<ans<<endl;
}

