#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

void fail(){
  puts("-1");
  exit(0);
}

int n;
ll d[125252];
int par[125252];
vi children[125252];
pll po[125252];

int cnt[125252];

int sz[125252];
ll val[125252];
void dfs1(int p){
  sz[p] = 1;
  val[p] = 0;
  for(int to : children[p]){
    dfs1(to);
    sz[p] += sz[to];
    val[p] += val[to] + sz[to];
  }
}
void dfs2(int p){
  if(val[p] != d[p])fail();
  for(int to : children[p]){
    ll tmp = val[to];
    val[to] = val[p] - sz[to] + (n-sz[to]);
    dfs2(to);
    val[to] = tmp;
  }
}

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%lld",d+i);

  REP(i,n)po[i] = pll(d[i], i);
  sort(po,po+n); reverse(po,po+n);
  
  map<ll,int> rev;
  REP(i,n)rev[d[i]] = i;

  REP(i,n)par[i] = -1;
  REP(i,n-1){
    int id = po[i].second;
    ll x = d[id];
    cnt[id]++;
    int a = cnt[id];
    int b = n-a;
    int c = b-a;
    if(c<=0)fail();
    ll nxt = x-c;
    if(rev.count(nxt)==0)fail();
    par[id] = rev[nxt];
    children[par[id]].push_back(id);
    cnt[par[id]] += cnt[id];
  }

  int root = 0;
  REP(i,n)if(par[i]==-1)root=i;

  dfs1(root);
  dfs2(root);
  REP(i,n)for(int j:children[i]){
    printf("%d %d\n",i+1,j+1);
  }
  return 0;
}
