#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
ll extgcd(ll a, ll b, ll& x, ll&y){
    ll d=a;
    if(b!=0){
        d=extgcd(b, a%b, y, x);
        y-=(a/b)*x;
    }
    else {
        x=1; y=0;
    }
    return d;
}

ll mod_inverse(ll a){
    ll x,y;
    extgcd(a,MOD,x,y);
    return (MOD+x%MOD)%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    ll A[N];
    rep(i,0,N) cin>>A[i];
    ll s=0;
    rep(i,1,N+1){
        s+=mod_inverse(i);
        s%=MOD;
    }
    ll res=0;
    rep(i,0,N){
        res+=s*A[i]%MOD;
        res%=MOD;
        s=((s-mod_inverse(N-i)+MOD)%MOD+mod_inverse(i+2))%MOD;
    }
    rep(i,1,N+1){
        res*=i;
        res%=MOD;
    }
    cout <<res<<"\n";
}