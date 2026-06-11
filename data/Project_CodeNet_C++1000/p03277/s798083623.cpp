// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define re register
using namespace std;
typedef long long ll;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=100000+10;

int n,mx;
int a[N],s[N],S[N];

int c[N<<1];
inline int lowbit(int x) { return x&-x; }
inline void add(int x,int y) {
    for (;x<=mx;x+=lowbit(x)) c[x]+=y;
}
inline int query(int x) {
    int res=0;
    for (;x;x-=lowbit(x)) res+=c[x];
    return res;
}

inline int check(int mid) {
    memset(c,0,sizeof(c)),mx=0;
    for (re int i=1;i<=n;++i) {
        if (a[i]<mid) s[i]=-1;
        else s[i]=1;
    }
    ll res=0;
    for (re int i=1;i<=n;++i) s[i]+=s[i-1],res+=(s[i]>=0);
    for (re int i=1;i<=n;++i) s[i]+=n+1,mx=max(mx,s[i]);
    for (re int i=1;i<=n;++i) res+=query(s[i]),add(s[i],1);
    ll cnt=1ll*n*(n-1)/2+n;
    return cnt-res<cnt/2+1;
}

int main() {
    n=read();
    for (re int i=1;i<=n;++i) S[i]=a[i]=read();
    sort(S+1,S+n+1); int m=unique(S+1,S+n+1)-S-1;
    for (re int i=1;i<=n;++i) a[i]=lower_bound(S+1,S+m+1,a[i])-S;
    int L=1,R=m,ans=0;
    while (L<R) {
        int mid=L+R+1>>1;
        if (check(mid)) L=mid;
        else R=mid-1;
    }
    printf("%d\n",S[L]);
    return 0;
}