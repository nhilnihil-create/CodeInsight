#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<bitset>
#include<climits>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
const int MAXN=2001;
int N,K,Q,ff[MAXN],A[MAXN],B[MAXN],tmp[MAXN],Minn,INF=INT_MAX;
void cacl(int l,int r){
    if(l>r||!l) return;
    int len=r-l+1;if(len<K) return;
    int tot=0;for(int i=l;i<=r;i++) B[++tot]=A[i];sort(B+1,B+tot+1);
    for(int i=1;i<=len-K+1;i++) tmp[++tmp[0]]=B[i];return;
}
int main(){
    N=read(),K=read(),Q=read();Minn=INF;for(int i=1;i<=N;i++) A[i]=tmp[i]=read();sort(tmp+1,tmp+N+1);
    int M=unique(tmp+1,tmp+N+1)-tmp-1;for(int i=1;i<=M;i++) ff[i]=tmp[i];for(int i=1;i<=N;i++) A[i]=lower_bound(tmp+1,tmp+M+1,A[i])-tmp;
    for(int i=1;i<=M;i++){
        int l=0;tmp[0]=0;
        for(int j=1;j<=N;j++){
            if(A[j]>=i) if(!l)  l=j;
            if(A[j]<i) {cacl(l,j-1);l=0;}
        }if(A[N]>=i) cacl(l,N);
        if(tmp[0]<Q) continue;sort(tmp+1,tmp+tmp[0]+1);
        Minn=min(Minn,ff[tmp[Q]]-ff[i]);
    }printf("%d\n",Minn);return 0;
}

