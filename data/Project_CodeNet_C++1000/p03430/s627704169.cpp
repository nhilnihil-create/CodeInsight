#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define rpd(i,a,b) for(register int i=a;i>=b;--i)
#define rep1(i,x) for(register int i=head[x];i;i=nxt[i])
typedef long long ll;
const int N=300+5;
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
string s;int n,m;int f[N][N][N];
void Max(int &x,int y){x=max(x,y);}
int main(){
    cin>>s;s=' '+s;
    n=s.length()-1;m=read();
    rep(i,1,n)rep(j,0,m)f[i][i][j]=1;
    rep(d,2,n)rep(i,1,n){
        int j=i+d-1;if(j>n)break;
        rep(k,0,m){
            if(k)Max(f[i][j][k],f[i][j][k-1]);
            Max(f[i][j][k],f[i+1][j][k]);
            Max(f[i][j][k],f[i][j-1][k]);
            if(s[i]==s[j])Max(f[i][j][k],f[i+1][j-1][k]+2);
            else if(k)Max(f[i][j][k],f[i+1][j-1][k-1]+2);
        }
    }
    printf("%d\n",f[1][n][m]);
    system("pause");
    return 0;
}
/*
区间DP
f[i][j][k]表示翻转[i,j]这个区间,修改k次的LCS
转移时修改一次因为翻转前后都能匹配,所以LCS+2
*/