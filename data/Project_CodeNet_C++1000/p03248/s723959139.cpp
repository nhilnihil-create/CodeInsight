#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,a,n) for(int i=n;i>=a;--i)
#define hr putchar(10)
#define pb push_back
#define lc (o<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
#define fi first
#define se second
#define io std::ios::sync_with_stdio(false)
#define endl '\n'
#define DB(a) ({REP(__i,1,n) cout<<a[__i]<<',';hr;})
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n) {ll r=1%P;for (a%=P;n;a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
ll inv(ll x){return x<=1?1:inv(P%x)*(P-P/x)%P;}
inline int rd() {int x=0;char p=getchar();while(p<'0'||p>'9')p=getchar();while(p>='0'&&p<='9')x=x*10+p-'0',p=getchar();return x;}
//head
const int N = 1e6+10;
char s[N];
int main() {
    io;
    cin>>(s+1);
    int len=strlen(s+1);
    if(s[1]=='0'||s[len]=='1') return puts("-1"),0;
    rep(i,1,len-1) if(s[i]!=s[len-i]) return puts("-1"),0;
    int rt=1;
    rep(i,2,len)
    {
        cout<<rt<<' '<<i<<endl;
        if(s[i-1]=='1')
            rt=i;
    }

}
