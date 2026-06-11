#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int N=1e5+5;
  
int n,m,f[N],ans,a[N],mid,b[N],c[N],ky;
ll num;
  
inline void update(int x,int y){ for(;x<=ky;x+=x&-x) f[x]+=y;}
inline int query(int x){ int an=0; for(;x;x-=x&-x) an+=f[x]; return an;}
  
inline ll calc(){
    ll an=0;
    b[0]=0,memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++) b[i]=b[i-1]+(a[i]<=mid?1:-1),c[i]=b[i];
    c[ky=n+1]=0,sort(c+1,c+ky+1),ky=unique(c+1,c+ky+1)-c-1;
    for(int i=0;i<=n;i++) b[i]=lower_bound(c+1,c+ky+1,b[i])-c;
     
    update(b[0],1);
    for(int i=1;i<=n;i++) an+=(ll)query(b[i]-1),update(b[i],1);
     
    return an;
}
  
inline void solve(){
    int L=1,R=1e9;
    while(L<=R){
        mid=L+R>>1;
        if(calc()>=num) ans=mid,R=mid-1;
        else L=mid+1;
    }
}
  
int main(){
    scanf("%d",&n),num=n*(ll)(n+1)>>1,num=(num>>1)+1;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
     
    solve();
     
    printf("%d\n",ans);
    return 0;
}