#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Mod 1000000007

ll a[101010],b[101010];

ll modinv(ll a) {
    ll m=Mod;
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    int n,i;
    cin>>n;

    ll kai=1;
    for(i=2;i<=n;i++){
        kai*=i;
        kai%=Mod;
    }

    for(i=1;i<=n;i++){
        a[i]=(kai*modinv(i))%Mod;
    }
    b[1]=a[1];
    for(i=2;i<=n;i++){
        b[i]=(a[i]+b[i-1])%Mod;
    }

    int s[n+1];
    for(i=1;i<=n;i++) cin>>s[i];

    ll ans;

    for(i=1;i<=n;i++){
        ans+=s[i]*((Mod+b[i]+b[n+1-i]-b[1])%Mod);
        ans%=Mod;
    }

    cout<<ans<<endl;

    
    return 0;
}