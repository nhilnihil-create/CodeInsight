#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define REP(a,b) for(int a=0;a<(b);++a)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isPossible(x) printf("%s\n",(x) ? "Possible" : "Impossible")
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define INF (1<<29)

// const long long INF = 1LL<<60;

#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define pie 3.14159265358979323846
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
// const int mod =(int)998244353;
const int mod =(int)1e9+7;

const int MAX =510000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(a<0)a=-a;
    if(b<0)b=-b;
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
  if(a<0)a=-a;
  if(b<0)b=-b;
    ll g;g=gcd(a,b);
    return b/g*a;
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}
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
ll RS(ll N,ll P,ll m){
    if(P==0){
        return 1;
    }else{
        if(P%2==0){
            ll t=RS(N,P/2,m);
            return t*t%m;
        }else{
            return N*RS(N,P-1,m)%m;
        }
    }
}
bool greater_pair(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first!=b.first){
        return a.first>b.first;
    }else{
        return a.second>b.second;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N=in();
    int A,B,C;cin>>A>>B>>C;
    vector<int> l(N);
    REP(i, N) cin >> l[i];
    sort(all(l));
    int ans=INF;
    REP(i,(1<<(2*N))){
        vector<int> a,b,c;
        REP(j,N){
            if((i>>(2*j))%4==0)continue;
            if((i>>(2*j))%4==1)a.pb(l[j]);
            if((i>>(2*j))%4==2)b.pb(l[j]);
            if((i>>(2*j))%4==3)c.pb(l[j]);
        }
        int _ans=0;
        int a_i=a.size(),b_i=b.size(),c_i=c.size();
        if(a_i==0||b_i==0||c_i==0)continue;
        int ans_a=INF;
        REP(ia,1<<a_i){
            if(ia==0)continue;
            int _ans_a=-10;
            int a_l=0;
            REP(ja,a_i){
                if((ia>>ja)&1){
                    _ans_a+=10;
                    a_l+=a[ja];
                }
            }
            _ans_a+=abs(a_l-A);
            ans_a=min(ans_a,_ans_a);
        }
        int ans_b=INF;
        REP(ib,1<<b_i){
            if(ib==0)continue;
            int _ans_b=-10;
            int b_l=0;
            REP(jb,b_i){
                if((ib>>jb)&1){
                    _ans_b+=10;
                    b_l+=b[jb];
                }
            }
            _ans_b+=abs(b_l-B);
            ans_b=min(ans_b,_ans_b);
        }
        int ans_c=INF;
        REP(ic,1<<c_i){
            if(ic==0)continue;
            int _ans_c=-10;
            int c_l=0;
            REP(jc,c_i){
                if((ic>>jc)&1){
                    _ans_c+=10;
                    c_l+=c[jc];
                }
            }
            _ans_c+=abs(c_l-C);
            ans_c=min(ans_c,_ans_c);
        }
        ans=min(ans_a+ans_b+ans_c,ans);
    }
    cout<<ans<<endl;
    return 0;
} 
