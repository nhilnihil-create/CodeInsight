#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
#include<stack>
#include<bitset>
#include<map>
#include<set>
#define rep(i,n) for(int i=0;(i)<(n);i++)
#define rep1(i,n) for(int i=1;(i)<=(n);i++)
#define mst(a,b) memset(a,b,sizeof(a))
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define dbg(a) cout<<"* "<< #a <<" : "<<a<<endl
#define fr first
#define se second
//#define ls x<<1
//#define rs x<<1|1
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define lowbit(x) x&(-x)
#define ac cout<<ans<<endl
//#define DEBUG 0
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-10;
const ull hashp=131;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+100;
int qpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1)ret=1ll*ret*a%mod;
		b>>=1;
		a=1ll*a*a%mod;
	}
	return ret;
}
int a[maxn],n;
int jc[maxn]={1},inv[maxn];
void init(){
	rep1(i,n){
		jc[i]=1ll*jc[i-1]*i%mod;
		inv[i]=qpow(i,mod-2);
	}
	rep1(i,n)inv[i]=(inv[i]+inv[i-1])%mod;
}
void solve(){
	scd(n);init();
	rep1(i,n)scd(a[i]);
	int ans=0;
	rep1(i,n)
		ans=(ans+1ll*a[i]*((inv[i]+inv[n-i+1]-1)%mod)%mod)%mod;
	ans=1ll*ans*jc[n]%mod;ans=(ans+mod)%mod;ac;
}
int main(){
    //IOS;
    //freopen("D:\\data.txt","r",stdin);
    //freopen("D:\\out.txt","w",stdout);
    solve();
 
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;;                                             ;;
    ;;         ;;            ;;;;;;;;;       ;;    ;;
    ;;        ;; ;;        ;;                ;;    ;;
    ;;       ;;   ;;       ;;                ;;    ;;
    ;;      ;;;;;;;;;      ;;                ;;    ;;
    ;;     ;;       ;;     ;;                      ;;
    ;;    ;;         ;;      ;;;;;;;;;       ;;    ;;
    ;;                                             ;;
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 
    return 0;
}
