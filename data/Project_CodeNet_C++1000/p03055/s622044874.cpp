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
vector<int> depth(mx,0);

void dfs(int n, int p, int d){
  depth[n] = d;
  for(auto to:v[n]){
    if(to==p) continue;
    dfs(to, n, d+1);
  }
}

int main(){
  int n;
  cin >> n;
  rep(i,n-1){
    int x,y; cin >> x >> y; x--; y--;
    v[x].emplace_back(y);
    v[y].emplace_back(x);
  }
  dfs(0,-1,0);
  int tmp = max_element(depth.begin(),depth.end()) - depth.begin();
  dfs(tmp,-1,0);
  tmp = max_element(depth.begin(),depth.end()) - depth.begin();
  int sz = depth[tmp]+1;
  if(sz%3!=2){
    cout << "First" << ln;
  } else {
    cout << "Second" << ln;
  }
  return 0;
}