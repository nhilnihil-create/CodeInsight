#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

const int inf = 1e9;
const ll linf = 1LL<<60;
const ll mod = 1e9 + 7;
const double eps = 1e-9;

/*{
}*/

int n, m;
vi g[100000];
int c[100000];
int num[100000];
bool flag;

void dfs(int cur, int col)
{
  if(c[cur] != -1){
    if(c[cur] != col){
      flag = true; 
    }
  }else{
    c[cur] = col;
    num[col]++;
    for(int e : g[cur]) dfs(e, col^1);
  }
}

int main()
{
  cin >> n >> m;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  fill(c, c+n, -1);

  dfs(0, 0);

  if(flag) cout << 1LL*n*(n-1)/2-m << endl;
  else cout << 1LL*num[0]*num[1]-m << endl;

  return 0;
}
