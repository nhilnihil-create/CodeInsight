#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vp  vector<pii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ls l,mid,rt<<1
#define rs mid+1,r,rt<<1|1
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
#define sf scanf
#define pf printf
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const double PI=acos(-1.0);
const int MAXN=1e5+5;
const int MAXM=2e6+5;
const int MOD=1e9+7;
int sgn(double x){if(fabs(x)<eps)return 0;if(x<0)return -1;else return 1;}
ll pw(ll a,ll n,ll mod){ll ret=1;while(n){if(n&1)ret=ret*a%mod;a=a*a%mod;n>>=1;}return ret;}
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
void inc(ll &a,ll b){a+=b;if(a>=MOD)a-=MOD;}
void dec(ll &a,ll b){a-=b;if(a<0)a+=MOD;}
int mul(int x, int y){ll z=1ll*x*y;return z-z/MOD*MOD;}
//head

const int sed=13331;
int n; char s[50];
map<pii,int>hs;
void add(int x){
    int t1=0,t2=0;
    rep(i,0,n)if(x&(1<<i))t1=t1*sed+(s[n+i]-'a'+1);
    per(i,0,n)if(!(x&(1<<i)))t2=t2*sed+(s[n+i]-'a'+1);
    //pf("%d %d\n",t1,t2);
    hs[mp(t2,t1)]++;
}
int gao(int x){
    int t1=0,t2=0;
    rep(i,0,n)if(x&(1<<i))t1=t1*sed+(s[i]-'a'+1);
    per(i,0,n)if(!(x&(1<<i)))t2=t2*sed+(s[i]-'a'+1);
    //pf("x=%d %d %d\n",x,t1,t2);
    return hs[mp(t1,t2)];
}
int main(){
    sf("%d%s",&n,s);
    rep(i,0,(1<<n))add(i);
    ll ans=0;
    rep(i,0,(1<<n))ans+=gao(i);
    pf("%lld\n",ans);
}
