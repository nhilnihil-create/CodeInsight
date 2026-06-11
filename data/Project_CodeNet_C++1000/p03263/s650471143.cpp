#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
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

int h,w;
int main( ){
    cin>>h>>w;
    vvi a(h,vi(w,0));
    ll sum=0;
    ll odd=0;
    int starti=-1,startj=-1;
    rep(i,0,h)rep(j,0,w){
        cin>>a[i][j];
        sum+=a[i][j];
        if(a[i][j]%2)odd++;
    }
    vpii ansres;
    if(sum%2)odd--;
    int wayj[]={0,0};
    int wayi[]={-1,1};
    bool way=true;
    int i=0,j=0;
    while(odd){
        if(a[i][j]%2==0){
            int ni=i+wayi[way];
            int nj=j+wayj[way];
            if(ni>=h||ni<0){
                way^=true;
                j++;
                continue;
            }
            i=ni; j=nj;
            continue;
        }
        while(odd&&a[i][j]%2){
            pii t=make_pair(i,j);
            ansres.push_back(t);
            a[i][j]--;
            int ni=i+wayi[way];
            int nj=j+wayj[way];
            if(ni>=h||ni<0){
                way^=true;
                j++;
                a[i][j]++;
                pii n=make_pair(i,j);
                ansres.push_back(n);
                continue;
            }
            i=ni; j=nj;
            pii n=make_pair(i,j);
            ansres.push_back(n);
            a[i][j]++;
        }
        odd-=2;
    }
    cout<<ansres.size()/2<<endl;
    for(int i=0;i<ansres.size();i+=2){
        pii first,second;
        first=ansres[i];
        second=ansres[i+1];
        cout<<first.first+1<<" "<<first.second+1<<" "<<second.first+1<<" "<<second.second+1<<endl;
    }
   return 0;
}


