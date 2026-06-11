#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const double pi = 3.141592653589793;

/*ll par[MAX];
ll Rank[MAX];
ll Gr[MAX];*/
vector<ll> par(MAX, 0);
vector<ll> Rank(MAX, 0);
vector<ll> Gr(MAX, 0);
ll Score=0;

void init(ll n){
    rep(i, n){
        par[i]=i;
        Rank[i]=0;
        Gr[i]=1;
    }
  	Score=n;

}

ll find(ll x){
    if(par[x]==x){
        return x;
    }
    else{
        return par[x]=find(par[x]);
    }
}

void unite(ll x, ll y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(Rank[x]<Rank[y]){
        Score-=(Gr[y]-1)*(Gr[y])/2;
      	Score-=(Gr[x]-1)*(Gr[x])/2;
        par[x]=y;
        Gr[y]+=Gr[x];
        Score+=(Gr[y]-1)*(Gr[y])/2;
    }
    else{
        par[y]=x;
        Score-=(Gr[x]-1)*(Gr[x])/2;
      	Score-=(Gr[y]-1)*(Gr[y])/2;
        Gr[x]+=Gr[y];
        Score+=(Gr[x]-1)*(Gr[x])/2;
        if(Rank[x]==Rank[y])Rank[x]++;
    }

}

bool same(ll x, ll y){
    return find(x)==find(y);
}

int main(){
    ll N, M;
    cin>>N>>M;
    vector<ll> A(M), B(M);
    rep(i, M){
        cin>>A[i]>>B[i];
        A[i]--; B[i]--;
    }
    init(N);
    vector<ll> Sc(M);
    Sc[M-1]=N*(N-1)/2;
    rep(i, M){
        unite(A[M-1-i], B[M-1-i]);
        if(i<M-1){
			Sc[M-2-i]=N*(N+1)/2-Score;
        }
      	//cout<<Score<<endl;
    }
    rep(i, M){
        cout<<Sc[i]<<endl;
    }
}