#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline void cmax(ll &a,ll b){if(a<b)a=b;}
const int N=100005;
int a[N],b[N];
int main(){
    ll s=0ll,t=0ll;
    int n,l,r,i;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&l,&r);
        a[i]= l;
        b[i]=-r;
    }
    sort(a,a+n+1);
    sort(b,b+n+1);
    for(i=n;~i;--i)cmax(s,t+=a[i]+b[i]);
    printf("%lld",s<<1);
    return 0;
}