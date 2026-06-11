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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

vector<int> v[mx];
vector<int> dep(mx,0);

void dfs(int n, int p, int d){
  dep[n] = d;
  for(auto to:v[n]){
    if(to==p) continue;
    dfs(to,n,d+1);
  }
}

int main(){
  int n;
  cin >> n;
  rep(i,n-1){
    int a,b; cin >> a >> b; a--; b--;
    v[a].emplace_back(b);
    v[b].emplace_back(a);
  }
  dfs(0,-1,0);
  int a = max_element(dep.begin(),dep.end()) - dep.begin();
  dfs(a,-1,0);
  int b = max_element(dep.begin(),dep.end()) - dep.begin();
  int d = dep[b]+1;
  if(d%3!=2){
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}