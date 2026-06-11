#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define pd pair<double,double>
#define ld long double
#define pld pair<ld,ld>
#define lg length()
#define sz size()
#define pb push_back
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005
#define x1 xdddddddddddddddddd
#define y1 ydddddddddddddddddd

ll n,a[100005],inv[100005],f[100005],mod=1e9+7,s,l,r,ans;

ll pwr(ll a, ll p){
    if(!p) return 1;
    ll t=pwr(a,p/2);
    t*=t; t%=mod;
    if(p%2) t*=a,t%=mod;
    return t;
}


int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n; f[0]=1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        inv[i]=pwr(i,mod-2);
        s+=inv[i];
        s%=mod;
        f[i]=f[i-1]*i%mod;
    }
    l=2; r=n;
    for(int i=1;i<=n;i++){
        ans+=s*a[i]; ans%=mod;
        s+=inv[l]; s-=inv[r];
        s%=mod; if(s<0) s+=mod;
        l++; r--;
    }
    ans*=f[n]; ans%=mod;
    cout << ans;
}
