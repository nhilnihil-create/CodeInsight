#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vvll=vector<vll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;
using vpii=vector<pair<int,int>>;
using plli=pair<ll,int>;
using vplli=vector<pair<ll,int>>;
using pllll=pair<ll,ll>;
using vpllll=vector<pair<ll,ll>>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(ll x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)
//試験導入
#define irep(i, end_i, begin_i) for (ll i = (ll)begin_i-1; i >= (ll)end_i; i--)

long long INF = 1LL<<60;
int main( ){
    int D;
    cin>>D;
    ll G;
    cin>>G;
    vi p(D);
    vi c(D);
    rep(i,0,D){
        cin>>p[i]>>c[i];
    }
    ll ans=INF;
    for(int i=0;i<1<<D;i++){
        ll res=0;
        ll pcnt=0;
        vb is_slv(D,false);
        rep(j,0,D){
            if(1&i>>j){
                is_slv[j]=true;
                res+=c[j]+p[j]*(j+1)*100;
                pcnt+=p[j];
            }
        }
        if(res>=G){
            chmin(ans,pcnt);
            continue;
        }
        irep(j,0,D){
            if(is_slv[j]==false){
                rep(k,0,p[j]+1){
                    if(res+k*(j+1)*100>=G){
                        chmin(ans,pcnt+k);
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


