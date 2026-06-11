#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N;
char s[40],a[40],b[40],c[40],d[40];
int cnt,dnt;
ll ans;
ll f[40][40];
void dp() {
    memset(f,0,sizeof f);
    f[0][0]=1;
    for(int i=0;i<=cnt;++i)
        for(int j=0;j<=dnt;++j) if(i+j)
            f[i][j]=f[i-1][j]*(c[i]==b[i+j])+f[i][j-1]*(d[j]==b[i+j]);//,printf("f[%d][%d]=%lld\n",i,j,f[i][j]);
    ans+=f[cnt][dnt];
}
int main() {
    scanf("%d",&N);
    scanf("%s",s+1);
    for(int i=1;i<=N;++i) a[i]=s[i],b[i]=s[N+N+1-i];
    for(int i=0;i<(1<<N);++i) {
        dnt=cnt=0;
        for(int j=0;j<N;++j) {
            if((1<<j)&i) c[++cnt]=a[j+1];
            else    d[++dnt]=a[j+1];
        }
        dp();
    }
    printf("%lld\n",ans);
    return 0;
}