#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,YZ,a[maxn],tree[maxn<<1],aa[maxn],l,r,mid;
int lowbit(int x){
    return x&(-x);
}
void add(int x){
    while(x<(maxn<<1)){
        ++tree[x];
        x+=lowbit(x);
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
bool check(int m){
    int cnt=0;
    memset(tree,0,sizeof(tree));
    for(re int i=1;i<=n;++i){
        if(a[i]<=m){
            aa[i]=1;
        }
        else{
            aa[i]=-1;
        }
    }
    aa[0]=0;
    for(re int i=1;i<=n;++i){
        aa[i]+=aa[i-1];
    }
    for(re int i=0;i<=n;++i){
        aa[i]+=maxn;
    }
    add(aa[0]);
    for(re int i=1;i<=n;++i){
        cnt+=query(aa[i]-1);
        add(aa[i]);
    }
    return cnt>=YZ;
}
signed main(){
    scanf("%lld",&n);
    YZ=n*(n+1)/4+1;
    for(re int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    l=0,r=1e9;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%lld\n",l);
    return 0;
}