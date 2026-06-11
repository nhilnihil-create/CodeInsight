#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cctype>
#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
using namespace std;

inline char gc() {
//  static char buf[100000],*p1,*p2;
//  return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
    return getchar();
}

template<class T>
int read(T &ans) {
    ans=0;char ch=gc();T f=1;
    while(!isdigit(ch)) {
        if(ch==EOF) return -1;
        if(ch=='-') f=-1;
        ch=gc();
    }
    while(isdigit(ch))
        ans=ans*10+ch-'0',ch=gc();
    ans*=f;return 1;
}

template<class T1,class T2>
int read(T1 &a,T2 &b) {
    return read(a)!=EOF&&read(b)!=EOF?2:EOF;
}

template<class T1,class T2,class T3>
int read(T1 &a,T2 &b,T3 &c) {
    return read(a,b)!=EOF&&read(c)!=EOF?3:EOF;
}

typedef long long ll;
const int Maxn=31000;
const int inf=0x3f3f3f3f;
const ll mod=1000000007;

int f[Maxn],pre[Maxn],suf[Maxn],n;

char readch() {
    char ch=gc();
    while(ch!='>'&&ch!='<') ch=gc();
    return ch;
}

signed main() {
//  freopen("test.in","r",stdin);
    read(n);f[1]=pre[1]=suf[1]=1;
    for(int i=2;i<=n;i++) {
        if(readch()=='<') for(int j=1;j<=i;j++) f[j]=pre[j-1];
        else for(int j=1;j<=i;j++) f[j]=suf[j];
        for(int j=1;j<=i;j++) pre[j]=(pre[j-1]+f[j])%mod;
        for(int j=i;j>=1;j--) suf[j]=(suf[j+1]+f[j])%mod;
    }
    printf("%d",pre[n]);
    return 0;
}