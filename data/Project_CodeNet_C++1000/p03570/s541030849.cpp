#include<cstdio>
#include<algorithm>
#include<cstring>
 
using namespace std;
const int maxn=300010;
int ans=0,tot=0,sum[maxn],a[maxn],f[maxn],g[1<<26],n,l,r;
char s[maxn];
void read(int &k){
    k=0; int f=1; char c=getchar();
    while (c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();
    while ('0'<=c&&c<='9')k=k*10+c-'0',c=getchar();
    k*=f;
}
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]^(1<<(s[i]-'a'));
    memset(f,32,sizeof(f)); memset(g,32,sizeof(g));
    g[0]=0;
    for (int i=1;i<=n;i++){
        f[i]=min(f[i],g[sum[i]]+1);
        for (int j=0;j<26;j++) f[i]=min(f[i],g[sum[i]^(1<<j)]+1);
        g[sum[i]]=min(g[sum[i]],f[i]);
    }
    printf("%d\n",f[n]);
    return 0;
}