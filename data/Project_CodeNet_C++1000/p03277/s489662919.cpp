#include <bits/stdc++.h>
typedef long long ll;
const int N=100005;
int n,mx;
int a[N],sum[N<<1],b[N],s[N];
int lowbit(int x) { return x&-x; }
void upd(int x) {
	while (x<=mx){
		sum[x]++;
		x+=lowbit(x); 
	}
}
int getsum(int x) {
    int ret=0;
    while (x){
    	ret+=sum[x];
    	x-=lowbit(x);
    }
    return ret;
}

int check(int mid) {
    memset(sum,0,sizeof(sum));
	mx=0;
    for (int i=1;i<=n;++i) {
        if (a[i]<mid) s[i]=-1;
        else s[i]=1;
    }
    ll ans=0;
    for (int i=1;i<=n;i++) s[i]+=s[i-1],ans+=(s[i]>=0);
    for (int i=1;i<=n;i++) s[i]+=n+1,mx=std::max(mx,s[i]);
    for (int i=1;i<=n;i++) ans+=getsum(s[i]),upd(s[i]);
    ll cnt=1ll*n*(n-1)/2+n;
    return cnt-ans<cnt/2+1;
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
    std::sort(b+1,b+n+1); 
	int m=std::unique(b+1,b+n+1)-b-1;
    for (int i=1;i<=n;++i) a[i]=std::lower_bound(b+1,b+m+1,a[i])-b;
    int l=1,r=m,ans=0;
    while (l<=r) {
        int mid=(l+r)>>1;
        if (check(mid)) l=mid+1,ans=b[mid];
        else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}