#include <bits/stdc++.h>
typedef long long LL;
#define rep(i,a,b) for(auto i=(a);i<=(b);++i)
#define per(i,a,b) for(auto i=(a);i>=(b);--i)
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define ls rt<<1
#define rs rt<<1|1
#define root 1,cnum,1
#define Pr pair<int,int>
#define Prd pair<double,double>
#define Prl pair<LL,LL>
#define fi first
#define se second
#define Abs(x) (x>0?x:x*-1)
#define lowbit(x) (x&(-x))
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF = 0x7FFFFFFF;
const LL LINF = 0x7FFFFFFFFFFFFF;
void guan() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

const LL mod = 1e9+7; 
const int maxn = 1010101;
LL t[maxn];
LL fact[maxn];
LL f[maxn], pref[maxn], inv_fact[maxn];

LL qpow(LL a, LL n) {
    LL sum = 1;
    while(n) {
        if(n&1) sum = sum*a%mod;
        a=a*a%mod;
        n>>=1;
    } return sum;
}
void init(int n) {
    fact[0] = 1;
    rep(i,1,maxn-10) fact[i] = fact[i-1]*i%mod;
    inv_fact[maxn-10] = qpow(fact[maxn-10],mod-2);
    per(i,maxn-11,0) inv_fact[i] = inv_fact[i+1]*(i+1)%mod;
    LL sum = 0;
    f[0] = 1;
    rep(i,1,n) f[i] = i%mod;
    pref[0] = 0;
    //cout << fact[n-1] << " " << inv_fact[n-2] << " " << f[n-2] << " " << qpow(2,mod-2) << endl;
    rep(i,1,n) pref[i] = (pref[i-1]+fact[n]*inv_fact[n-i+1]%mod*f[n-i+1]%mod*qpow(i,mod-2)%mod*fact[n-i]%mod)%mod;
}
int main() {
    guan();
    int d, h, k, p, q;
    LL n, m;
    while(cin >> n) {
        init(n);
        rep(i,1,n) cin >> t[i];
        LL ans = 0;
        //cout << pref[1] << " " << pref[2] << " " << pref[3] << endl;
        rep(i,1,n) {
            ans = (ans + (pref[i]+pref[n-i+1]-pref[1]+mod)%mod*t[i]%mod)%mod;
            //cout << ans << " ";
        }
        cout << ans << endl;
        //cout << endl;
    }
    return 0;
}