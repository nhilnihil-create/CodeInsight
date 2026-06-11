#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

bool used[200020];
vector<int> v[200020];
ll ans;
int cnt;
int c[200020];
int val[200020];

void dfs(int from,int now){
  used[now]=true;
  val[now]=c[cnt];
  cnt++;
  rep(i,v[now].size()){
    if(!used[v[now][i]]){
      dfs(now,v[now][i]);
    }
  }
}

int main(){
  int n;
  cin >> n;
  pint p[n];
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--,b--;
    p[i]={a,b};
    v[a].push_back(b);
    v[b].push_back(a);
  }
  rep(i,n)cin >> c[i];
  sort(c,c+n,greater<int>());
  dfs(-1,0);
  rep(i,n-1){
    ans+=min(val[p[i].first],val[p[i].second]);
  }
  cout << ans << endl;
  rep(i,n)cout << val[i] << ' ';
  cout << endl;
return 0;}