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
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(ll i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=200010;
const ll mod=1e9+7;

vector<int> v[mx];
 
vector<int> low(mx,-1);
vector<int> ord(mx,-1);
vector<pair<int,int>> bridge;                            //bridge
vector<int> art;                                         //articulation list
 
void dfs(int &count, int from, int x){
  ord[x] = count++;
  low[x] = ord[x];
  bool isart=false;
  int cnt=0;
  
  for(auto to:v[x]){
    if(to==from){ continue; }                            //kitatokoro
    if(ord[to]==-1){                                     // unseen
      cnt++;
      dfs(count,x,to); 
      if(ord[x]<low[to]){ bridge.emplace_back(min(x,to),max(x,to)); } //bridge?       
      if(from!=-1 && ord[x]<=low[to]){ isart=true; }
      low[x] = min(low[x],low[to]);
    } else { low[x] = min(low[x],ord[to]); }
  }
  if(from==-1 && cnt>1){ isart=true; }
  if(isart){ art.emplace_back(x);}                       //articulation?
}


int main(){
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int x,y; cin >> x >> y; x--; y--;
    v[x].emplace_back(y);
    v[y].emplace_back(x);
  }
  int cnt = 0;
  dfs(cnt,-1,0);
  int ans = bridge.size();
  cout << ans << ln;
  return 0;
}