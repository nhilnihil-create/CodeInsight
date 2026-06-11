#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp=boost::multiprecision;
//#define mulint mp::cpp_int
//#define mulfloat mp::cpp_dec_float_100
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcountll(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;
//struct edge{lint to,num;};

vector<int> edge[MAX_N];
bool reach[MAX_N];
lint ans[MAX_N];

int dfs(int now){
    if(reach[now]) return 0;
    reach[now]=true;
    rep(i,edge[now].size()){
    }
}

lint par[200500]; //MAX_N
lint ufsize[200050]; //MAX_N

void init(lint x){
  rep(i,x) par[i]=i,ufsize[i]=1;
}

lint root(lint x){
  if(par[x]==x) return x;
  else return par[x]=root(par[x]);
}

bool same(lint x,lint y){
  return root(x)==root(y);
}

void unite(lint x,lint y){
  x=root(x);
  y=root(y);
  if(x==y) return;
  lint s=ufsize[x]+ufsize[y];
  ufsize[x]=s,ufsize[y]=s;
  par[x]=y;
}

lint size(lint x){
  return ufsize[root(x)];
}

int main(void){
    int N,M;
    cin >> N >> M;
    int a[M],b[M];
    rep(i,M) cin >> a[i] >> b[i],a[i]--,b[i]--;
    int ans=0;
    rep(i,M){
        init(N);
        rep(j,M) if(i!=j) unite(a[j],b[j]);
        if(size(0)!=N) ans++;
    }
    cout << ans << endl;
}