#include <bits/stdc++.h>
#define N 5005
#define INF 10000000000000LL
using namespace std;
int n,A,B,p[N],pos[N],cnt[N][N];
long long f[N][N];
int main(){
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=n;++i){
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    for(int i=n;i;--i)
        for(int j=1;j<=n;++j)
            if(pos[j]>=i)cnt[i][j]=cnt[i+1][j]+(j<=p[i]);
    for(int j=n;j;--j)
        for(int i=n;i;--i)
            if(!cnt[i][j])f[i][j]=f[i][j+1];
            else{
                f[i][j]=min(f[i][j+1]+B,f[pos[j]+1][j+1]+1LL*A*(cnt[i][j]-1));
                //printf("cnt=%d f[%d][%d]=",cnt[i][j]-1,i,j),cout<<f[i][j]<<endl;
            }
    cout<<f[1][1]<<endl;
}
