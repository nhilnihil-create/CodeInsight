#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define REPr(i,n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define FORqr(i, m , n) for(int i = (n);i >=(m);--i)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define SCLLD(n) scanf("%lld",&n)
#define SCLLD2(m,n) scanf("%lld%lld",&m,&n)
#define SCLLD3(m,n,k) scanf("%lld%lld%lld",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define VSCD(v,N) REP(i,N){int (x); SCD(x); v.PB(x);}
#define VSCLLD(v,N) REP(i,N){long long (x); SCLLD(x); v.PB(x);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x,S) (S.count(x) != 0)
#define M0(x) memset(x,0,sizeof(x))
#define FILL(x,y) memset(x,y,sizeof(x))
#define MM(x) memset(x,-1,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef vector<int> VI;
typedef vector < VI > VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const ll MOD = 1000000007;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////
int main(){
    int N;
    SCD(N);
    vector<ll> a(N);
    vector<PII> ans;
    int Min,min;
    ll M,m;

    REP(i,N){
        SCLLD(a[i]);
    }

    M = a[0]; Min = 0;
    m = a[0]; min = 0;

    REP(i,N){
        if (chmax(M,a[i])) Min = i;
        if (chmin(m,a[i])) min = i;
    }

    int mode = 0;
    if (m >= 0) mode = 1;
    if (M <= 0) mode = -1;
    //cout << M << " " << m << " " << Min << " " << min << " " << mode << "\n";
    if (mode == 0){
        if (M >= -m){
            REP(i,N){
                if (i == Min) continue;
                a[i] += a[Min];
                ans.PB(MP(Min+1,i+1));
                mode = 1;
            }
        }else{
            REP(i,N){
                if (i == min) continue;
                a[i] += a[min];
                ans.PB(MP(min+1,i+1));
                mode = -1;
            }
        }
    }

    if (mode == 1){
        REP(i,N-1){
            a[i+1] += a[i];
            ans.PB(MP(i+1,i+2));
        }
    }else{
        REPr(i,N-1){
            a[i] += a[i+1];
            ans.PB(MP(i+2,i+1));
        }
    }

    int outm = ans.size();
    PRINTD(outm);

    REP(i,outm){
        printf("%d %d\n",ans[i].fst,ans[i].snd);
    }

}




