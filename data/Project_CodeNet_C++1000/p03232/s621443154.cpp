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
LL a[maxn];
LL pre[maxn];
LL inv[maxn];
LL A[maxn];
void init() {
    inv[1] = 1;
    rep(i,2,maxn-1) {
        inv[i] = inv[mod%i]*(mod-mod/i)%mod;
    }
    pre[0] = 0;
    rep(i,1,maxn-1) pre[i] = (pre[i-1]+inv[i])%mod;
    A[0] = 1;
    rep(i,1,maxn-1) A[i] = A[i-1]*i%mod;
}
int main() {
    guan();
    int d, h, k, p, q;
    LL n, m;
    init();
    while(cin >> n) {
        LL ans = 0;
        rep(i,1,n) {
            cin >> m;
            ans = (ans + (pre[i] + pre[n-i+1] - 1 + mod) % mod * m % mod * A[n] % mod) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}