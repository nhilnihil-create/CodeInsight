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
    int N,K;
    cin>>N>>K;
    ll sum=0;
    int val;
    vi v;
    rep(i,0,N)cin>>val,v.push_back(val);
    ll ans=-INF;

    rep(l,0,K+1){
        rep(r,0,K-l+1){
            ll rest=K-(l+r);
            if(l+r>N||rest<0)break;
            ll sum=0;
            priority_queue<int,vi,greater<int>> q;
            rep(i,0,r)q.push(v[i]),sum+=v[i];
            rep(i,0,l)q.push(v[N-1-i]),sum+=v[N-1-i];
            int cnt=0;
            while(cnt<(r+l)&&cnt<rest){
                int minus=q.top();
                q.pop();
                if(minus>=0)break;
                cnt++;
                sum-=minus;
            }
            chmax(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}


