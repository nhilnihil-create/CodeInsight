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

const int mx=100010;
const ll mod=1e9+7;

int cnt;
vector<int> ch(10010);
vector<int> v[10010];

void dfs(int x, int p){
  ch[x] = cnt;
  cnt++;
  for(auto to:v[x]){
    if(to==p) continue;
    dfs(to,x);
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
  vector<P> c(n);
  int ans = 0;
  rep(i,n){
    cin >> c[i].F;
    c[i].S = i;
    ans += c[i].F;
  }
  sort(c.rbegin(),c.rend());
  ans -= c[0].F;

  cnt = 0;
  dfs(0,-1);

  cout << ans << endl;
  rep(i,n){
    cout << c[ch[i]].F << (i!=n-1?" ":"");
  }
  cout << endl;

  return 0;
}