#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define rpe(i,r,l) for(int i=(r);i>=(l);--i)
#define rpp(i,x,e,head) for(int i=head[x];~i;i=e[i].next)
#define dyes cerr<<"yes"<<endl
#define dbg(x) cerr<<#x<<"="<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pts puts("")
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
inline ll readll(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1LL;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
template <class T> inline void chmax(T &a,T b){if(a<b) a=b;}
template <class T> inline void chmin(T &a,T b){if(a>b) a=b;}
inline void swap(int &a,int &b){int c=a;a=b;b=c;}
using namespace std;
#define mst(a,val) memset(a,val,sizeof(a))
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define mp(i,j) make_pair(i,j)
#define fi first
#define sc second
#define inf (0x3f3f3f3f)
#define infl (0x3f3f3f3f3f3f3f3fLL)
#define forvec(i,j) for(vector<int>::iterator i=j.begin();i!=j.end();++i)
#define forvecv(i,j) for(vector<int>::iterator i=--j.end();i>=j.begin();--i)
//=====================head end======================//
const int N=2e5+10;
const int P=998244353;
int n,a[N],b[N],S;
int c[N],d[N];
inline int find(int l,int r){
    return ((int)(upper_bound(d+1,d+n+1,r)-d)-((int)(lower_bound(d+1,d+n+1,l)-d)))&1;
}
int main(){
    n=read();rep(i,1,n) a[i]=read();rep(i,1,n) b[i]=read();
    int ans=0;
    rep(i,0,29){
        S=(1<<i+1)-1;
        rep(j,1,n) c[j]=a[j]&S;
        rep(j,1,n) d[j]=b[j]&S;
//        rep(j,1,n) cerr<<c[j]<<" ";pts;
//        rep(j,1,n) cerr<<d[j]<<" ";pts;
        sort(c+1,c+n+1);sort(d+1,d+n+1);
        int qaq=0;
        int L1=1<<i,R1=(1<<i+1)-1;
        int L2=(1<<i+1)|(1<<i),R2=(1<<i+2)-1;
//        debug("L1=%d R1=%d\n",L1,R1);
//        debug("L2=%d R2=%d\n",L2,R2);
        rep(j,1,n){
            qaq^=find(L1-c[j],R1-c[j]);
            qaq^=find(L2-c[j],R2-c[j]);
        }
        if(qaq) ans|=(1<<i);
    }
    printf("%d\n",ans);
    return 0;
}
