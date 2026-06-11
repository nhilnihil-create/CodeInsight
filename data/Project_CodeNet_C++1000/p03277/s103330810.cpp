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
int a[N],s[N],ss[N];

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
        if (s[i]<mid) ss[i]=-1;
        else ss[i]=1;
    }
    ll res=0;
    for (re int i=1;i<=n;++i) ss[i]+=ss[i-1],res+=(ss[i]>=0);
    for (re int i=1;i<=n;++i) ss[i]+=n+1,mx=max(mx,ss[i]);
    for (re int i=1;i<=n;++i) res+=query(ss[i]),add(ss[i],1);
    ll cnt=1ll*n*(n-1)/2+n;
    /*if(mid==9)
      cout<<res<<endl;*/
    return cnt-res<cnt/2+1;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>s[i];
       a[i]=s[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=n;
    int ans=0;
    while(l<=r)
    {
       int mid=(l+r)>>1;
       if(check(a[mid]))
       {
         l=mid+1;
         ans=a[mid];
       } 
       else
       {
          r=mid-1;
       }
    }
    cout<<ans<<endl;
    return 0;
}