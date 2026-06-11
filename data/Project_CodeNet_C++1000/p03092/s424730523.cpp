#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define mem(x,num) memset(x,num,sizeof x)
#define reg(i,x) for(int i=last[x];i;i=e[i].next)
using namespace std;
inline ll read(){
    ll f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//******head by yjjr******
const int maxn=5e3+6;
int n,p[maxn];
ll f[maxn][maxn],A,B;
int main(){
    n=read(),A=read(),B=read();
    rep(i,1,n){int x=read();p[x]=i;}
    mem(f,0x20);
    f[0][0]=0;
    rep(i,1,n+1)rep(j,0,i)
        if(p[i]>p[j]){
            f[i][i]=min(f[i][i],f[i-1][j]);
            f[i][j]=min(f[i][j],f[i-1][j]+B);
        }else f[i][j]=min(f[i][j],f[i-1][j]+A);
    cout<<*min_element(f[n],f[n]+n+1)<<endl;
    return 0;
}