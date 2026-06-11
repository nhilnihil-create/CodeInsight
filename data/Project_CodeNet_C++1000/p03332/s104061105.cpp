#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=998244353;
ll gcd (ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}
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
ll mod_inverse(ll a, ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
//n!modp
ll fact[300020]; //0<=n<pについてn! modpのテーブルO(p)
//n!=a p＾eとした時のa modpを求める。O(log_p n)
ll mod_fact(ll n, ll p, ll& e){
    e=0;
    if(n==0) return 1;
    
    //pの倍数の部分を計算
    ll res=mod_fact(n/p,p,e);
    e+=n/p;
    
    //(p-1)!≡-1なので(p-1)!^(n/p)はn/pの偶奇だけで計算できる
    if(n/p%2!=0) return res*(p-fact[n%p])%p;
    return res*fact[n%p]%p;
}

//nCk modpを求める。O(log_p n)
ll mod_comb(ll n, ll k, ll p){
    if(n<0||k<0||n<k) return 0;
    ll e1, e2, e3;
    ll a1=mod_fact(n,p,e1), a2=mod_fact(k,p,e2), a3=mod_fact(n-k,p,e3);
    if(e1>e2+e3) return 0;
    return a1*mod_inverse(a2*a3%p,p)%p;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N,A,B,K;
    cin>>N>>A>>B>>K;
    ll x,y;
    ll g=extgcd(A, B, x, y);
    if(K%g){
        cout <<0<<"\n";
        return 0;
    }
    x*=K/g;
    y*=K/g;
    ll m=max(-g*x/B,(y-N)*g/A), M=min(g*y/A,(N-x)*g/B);
    fact[1]=1;
    rep(i,2,300020){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    ll ans=0;
    rep(i,m,M+1){
        ans+=mod_comb(N, x+B/g*i, MOD)*mod_comb(N, y-A/g*i, MOD);
        ans%=MOD;
    }
    cout <<ans<<"\n";
}