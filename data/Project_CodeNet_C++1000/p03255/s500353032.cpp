#include<bits/stdc++.h>
#define maxn 352534

using namespace std;
typedef long long ll;
ll a[maxn],n,m,k,r,d,s[maxn],ans,mm;
ll c(ll x){
    ll res=x*r+(s[n]-s[n-x])*5;
    m=n-x; k=5;
    while (m){
        mm=max(0ll,m-x);
        res+=k*(s[m]-s[mm]);
        if (res>=2e15) return 2e15;
        k+=2; m=mm;
    }
    return res;
}

int main(){
    cin >> n >> r;
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ans=c(1);
    for (int i=2;i<=n;i++) ans=min(ans,c(i));
    cout << ans+r*n << endl;
}
