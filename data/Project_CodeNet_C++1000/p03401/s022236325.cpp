#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vi=vector<int>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(T x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define rvrep(i,n) for(ll i=n-1;i>(ll)0;i--)
#define rep2(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)

long long INF = 1LL<<60;
int main( ){
    int n;
    cin>>n;
    vi a(n);
    rep(i,n)cin>>a[i];
    vll sum(n,0);
    sum[0]=abs(a[0]);
    for(int i=0;i<n-1;i++)sum[i+1]=sum[i]+abs(a[i+1]-a[i]);
    vll bsum(n,0);
    bsum[n-1]=abs(a[n-1]);
    for(int i=n-1;i>0;i--)bsum[i-1]=bsum[i]+abs(a[i]-a[i-1]);
    rep(i,n){
        ll res;
        if(i!=0&&i!=n-1){
            res=sum[i-1]+abs(a[i-1]-a[i+1])+bsum[i+1];
        }
        else{
            if(i==0)res=abs(a[1])+bsum[1];
            else res=sum[n-2]+abs(a[n-2]);
        }
        cout<<res<<endl;
    }
    return 0;
}


