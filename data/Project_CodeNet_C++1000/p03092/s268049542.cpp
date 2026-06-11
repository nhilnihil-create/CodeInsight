#include<bits/stdc++.h>
using namespace std;

#define int long long 

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 5000+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int n,a,b,f[maxn][maxn],p[maxn];

signed main() {
    read(n),read(a),read(b);
    for(int i=1,x;i<=n;i++) read(x),p[x]=i;
    memset(f,63,sizeof f);
    for(int i=1;i<=n+1;i++) f[0][i]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=p[i];j++) f[i][j]=f[i-1][j]+b;
        for(int j=p[i]+1;j<=n+1;j++) f[i][j]=f[i-1][j]+a;
        f[i][p[i]+1]=min(f[i][p[i]+1],f[i-1][p[i]]);
        for(int j=2;j<=n+1;j++) f[i][j]=min(f[i][j],f[i][j-1]);
        // for(int j=1;j<=n+1;j++) printf("%d ",f[i][j]);puts("");
    }
    write(f[n][n+1]);
    return 0;
}
