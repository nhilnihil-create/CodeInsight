#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
//const int MOD=998244353;

const double PI=3.14159265359;

long long modpow(long long x, long long n, long long m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<long long> v(n+1), hs(n+1), b(n+1), nfact(n+1);
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }
    
    hs[1]=1;
    nfact[1]=1;
    for(int i=2; i<=n; i++){
        hs[i]=hs[i-1]+modpow(i,MOD-2,MOD);
        hs[i]%=MOD;
        nfact[i]=i*nfact[i-1];
        nfact[i]%=MOD;
    }
    
    for(int i=1; i<=n; i++){
        b[i]=hs[n-i+1]+hs[i]-1;
        b[i]%=MOD;
    }
    
    long long ans=0;
    for(int i=1; i<=n; i++){
        ans+=b[i]*v[i];
        ans%=MOD;
    }
    ans*=nfact[n];
    ans%=MOD;
    cout<<ans;
    
    
    
    
    
    return 0;
    
}