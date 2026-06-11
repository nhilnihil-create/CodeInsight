#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcountll

#define INF 1e16
#define mod 1000000007

ll N;
ll D[100010];
ll sz[100010];
vector<int> ord;
vector<int> g[100010];
vector<P> res;
map<ll,int> idx;

ll dfs(int v){
  ll sum=0;
  for(int nv : g[v]){
    sum+=dfs(nv)+sz[nv];
  }
  return sum;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>N;
  rep(i,N){
    cin>>D[i];
    ord.push_back(i);
    sz[i]=1;
    idx[D[i]]=i;
  }
  sort(all(ord),[=](const int& a,const int& b){ return D[a] > D[b];});
  rep(j,ord.size()-1){
    int i=ord[j];
    ll nsz=D[i]+2*sz[i]-N;
    if(idx.find(nsz)==idx.end()){
      cout<<-1<<endl;
      return 0;
    }
    int nxt=idx[nsz];
    sz[nxt]+=sz[i]; res.push_back(P(nxt,i)); g[nxt].push_back(i);
  }
  if(sz[ord.back()]!=N){
    cout<<-1<<endl;
    return 0;
  }
  if(dfs(ord.back())!=D[ord.back()]){
    cout<<-1<<endl;
    return 0;
  }
  rep(i,res.size())cout<<res[i].fi+1<<" "<<res[i].se+1<<endl;

  return 0;
}
