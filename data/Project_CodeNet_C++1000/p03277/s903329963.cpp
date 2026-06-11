#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int maxm=1e5+10;
const int mod=1e9+7;
typedef long long ll;
ll pre[maxn],tree[maxn];
inline int lowbit(int x){return x&-x;}
inline void update(int x,int val){
    for (int i=x; i<maxn; i+=lowbit(i)) tree[i]+=val;
}
ll query(ll x){
    ll res=0;
    for (int i=x; i>0; i-=lowbit(i)) res+=tree[i];
    return res;
}
inline void init(){
    for (int i=0; i<maxn; i++) tree[i]=0;
    pre[0]=0;
}
ll n,a[maxn],tmp;
bool check(ll x){
    init();
    for (int i=1; i<=n; i++) pre[i]=pre[i-1]+(a[i]>=x?1:-1);
    ll res=0;
    for (int i=0; i<=n; i++) {
        res+=query(maxm+pre[i]);
        update(pre[i]+maxm,1);
    }
    return res>=tmp;
}

int main(){
    while(scanf("%lld",&n)==1){
        tmp=1ll*n*(n+1)/4;
        ll l=0,r=0;
        for (int i=1; i<=n; i++) scanf("%lld",&a[i]),r=max(r,a[i]);
        while(l<=r){
            ll mid=l+r>>1;
            if(check(mid)) l=mid+1;
            else r=mid-1;
        }
        printf("%lld\n",r);
    }
    return 0;
}
