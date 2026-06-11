#include <bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10;
const int mod=1e9;
typedef long long LL;

int n,m,c1,c2,v,t;
int x[MAXN],y[MAXN];
int f[MAXN],g[MAXN];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=n;i++) scanf("%d",&y[i]);
    int ans=0;
    for(int k=1;k<=29;k++){
        int bas=1<<(k-1);
        for(int i=1;i<=n;i++) f[i]=x[i]%(2*bas);
        for(int i=1;i<=n;i++) g[i]=y[i]%(2*bas);
        sort(f+1,f+n+1);
        sort(g+1,g+n+1);
        int l1,l2,r1,r2;
        l1=l2=r1=r2=n;
        int num=0;
        for(int i=1;i<=n;i++){
            /*for(int j=1;j<=n;j++){
                if (3*bas<=f[i]+g[j] && f[i]+g[j]<4*bas) num++;
                if (bas<=f[i]+g[j] && f[i]+g[j]<2*bas) num++;
            }*/
            while(l1>=1 && g[l1]+f[i]>=bas) l1--;
            while(l2>=1 && g[l2]+f[i]>=3*bas) l2--;
            while(r1>=1 && g[r1]+f[i]>=2*bas) r1--;
            while(r2>=1 && g[r2]+f[i]>=4*bas) r2--;
            int tmp=max(0,r1-l1)+max(0,r2-l2);
            num=(num+tmp)%2;
        }
        num%=2;
        if (num==1) ans+=bas;
    }
    printf("%d\n",ans);
    return 0;
}