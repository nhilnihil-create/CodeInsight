#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6;
ll x[N],s[N],l[N],r[N];
int v[N];
int main(){
    int n; ll c; cin>>n>>c;
    rep(i,1,n) scanf("%lld%d",&x[i],&v[i]),s[i]=s[i-1]+v[i];
    rep(i,1,n) l[i]=max(l[i-1],s[i]-x[i]);
    per(i,n,1) r[i]=max(r[i+1],(s[n]-s[i-1])-(c-x[i]));
    ll ans=max(l[n],r[1]);
    rep(i,1,n) ans=max(ans,s[i]-2*x[i]+r[i+1]);
    per(i,n,1) ans=max(ans,(s[n]-s[i-1])-2*(c-x[i])+l[i-1]);
    cout<<ans<<endl;
    return 0;
}
