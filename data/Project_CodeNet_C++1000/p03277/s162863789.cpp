// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
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
const int LIM=100005;

int n,S[N],a[N],b[N];

int c[(LIM<<1)+10];
inline void add(int x,int y) { for (;x<=LIM<<1;x+=x&-x) c[x]+=y; }
inline int sum(int x) { int s=0; for (;x;x-=x&-x) s+=c[x]; return s; }

inline ll calc(int mid) {
    for (re int i=1;i<=n;++i) b[i]=a[i]<mid?-1:1;
    for (re int i=2;i<=n;++i) b[i]+=b[i-1];
    memset(c,0,sizeof(c)); add(LIM,1); ll res=0;
    for (re int i=1;i<=n;++i) res+=i-sum(b[i]+LIM),add(b[i]+LIM,1);
    return res;
}

inline int check(int mid) { return calc(S[mid])<1ll*n*(n+1)/2/2+1; }

int main() {
    n=read();
    for (re int i=1;i<=n;++i) S[i]=a[i]=read();
    sort(S+1,S+n+1); int top=unique(S+1,S+n+1)-S-1;
    int L=1,R=top;
    while (L<R) {
        int mid=(L+R+1)>>1;
        if (check(mid)) L=mid;
        else R=mid-1;
    }
    printf("%d\n",S[L]);
    return 0;
}
