#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> s(n+1,0);
    for(ll i=1;i<=n;i++){
        s[i]=(modpow(i,mod-2)+s[i-1])%mod;
    }
    ll ret=0;
    for(int i=0;i<n;i++){
        ret+=a[i]*(s[i+1]+s[n-i]-1)%mod;
        ret%=mod;
    }
    for(ll i=1;i<=n;i++){
        ret*=i;
        ret%=mod;
    }
    ret+=mod;
    ret%=mod;
    cout << ret<<endl;
    return 0;
}
