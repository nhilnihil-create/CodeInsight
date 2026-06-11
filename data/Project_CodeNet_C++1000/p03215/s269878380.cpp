#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define ll long long
using namespace std;
const int N=1e6+6;
int a[N]; ll s[N],b[N];
int main(){
	int n,k,m=0; scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	rep(i,1,n) rep(j,i,n) b[++m]=s[j]-s[i-1];
    ll ans=0;
    per(j,60,0){
        int cnt=0;
        rep(i,1,m) if (b[i]>>j&1) ++cnt;
        if (cnt>=k){
            ans|=1LL<<j; int t=0;
            rep(i,1,m) if (b[i]>>j&1) b[++t]=b[i];
            m=t;
        }
    }
    cout<<ans<<endl;
}
