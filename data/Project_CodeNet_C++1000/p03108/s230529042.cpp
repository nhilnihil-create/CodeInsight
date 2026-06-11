#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
const ll MOD = 1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>

int N,M;
int a[100001];
int b[100001];


struct UnionFind{
    vector<int> par,s;
    UnionFind(int N) : par(N),s(N){
        REP(i,N){
            par[i] = i;
            s[i] = 1;
        }
    }
    int root(int x){
        if(par[x]==x){ return x; }
        else{ 
          par[x]= root(par[x]);
          return par[x];
        }
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if( rx!=ry ){
            par[rx] = ry;
            s[ry] += s[rx];
        }
    }
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return (rx==ry);
    }
    int size(int x){
        int rx = root(x);
        return s[rx];
    }
};

int main(){
    cin >>N>>M;
    UnionFind uf = UnionFind(N+1);
    for(int i=1;i<=M;++i){
        cin >> a[i] >> b[i];
    }
    ll ans[M+1];
    ans[M] = N*(N-1)/2;
    REPR(i,M-1){
        int x = a[i+1];
        int y = b[i+1];
        
        if(uf.root(x)==uf.root(y)){
            ans[i] = ans[i+1];
        }else{
            ans[i] = ans[i+1] - uf.size(x)*uf.size(y);
        }
        uf.unite(x,y);
    }
    
    for(int i=1;i<=M;++i){
        cout << ans[i]-ans[0] << "\n";
    }
}
