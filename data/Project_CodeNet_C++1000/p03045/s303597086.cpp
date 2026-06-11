#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=998244353;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
vector<int>kaijo;
void init_fact(int n){
    kaijo.resize(n+1);
    kaijo[0]=1;
    for(int i=1;i<=n;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
int comb(int a,int b){
    //if(!kaijo[0])init_fact(2000010);
    return kaijo[a]*modpow(kaijo[a-b],mod-2)%mod*modpow(kaijo[b],mod-2)%mod;
}
int inv(int x){
    x=modpow(x,mod-2);
    return x;
}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){
    double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
    double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
    double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
    double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
    return tc*td<0&&ta*tb<0;
}
int n,m;
int x[100010],y[100010],z[100010];int par[100010],siz[100010];
void init(int x){
    rep(i,x){
        par[i]=i;
        siz[i]=1;
    }
}
int find(int x){
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    if(siz[x]<siz[y])swap(x,y);
    par[y]=x;
    siz[x]+=siz[y];
}
bool same(int x,int y){
    return find(x)==find(y);
}
int size(int x){
    return siz[find(x)];
}
signed main(){
    cin>>n>>m;
    init(n);
    rep(i,m){
        cin>>x[i]>>y[i]>>z[i];
        z[i]%=2;
        unite(x[i]-1,y[i]-1);
    }
    set<int>st;
    rep(i,n)st.insert(find(i));
    cout<<st.size()<<endl;
    return 0;
}