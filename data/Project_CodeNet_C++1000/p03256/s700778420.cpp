/*input
13 23
ABAAAABBBBAAB
7 1
10 6
1 11
2 10
2 8
2 11
11 12
8 3
7 12
11 2
13 13
11 9
4 1
9 7
9 6
8 13
8 6
4 10
8 7
4 3
2 1
8 12
6 9
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long 
#define double long double
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define RE(i,n) for (int i = 1; i <= n; i++)
#define RED(i,n) for (int i = n; i > 0; i--)
#define REPS(i,n) for(int i = 1; (i*i) <= n; i++)
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int INF = 1e18+1;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int raise(int a,int n,int m = MOD){
  if(n == 0)return 1;
  if(n == 1)return a;
  int x = 1;
    x *= raise(a,n/2,m);
    x %= m;
    x *= x;
    x %= m;
    if(n%2)x*= a;
    x %= m;
    return x;
}

int floor1(int n,int k){
    if(n%k == 0 || n >= 0)return n/k;
    return (n/k)-1;
}

int ceil1(int n,int k){
    return floor1(n+k-1,k);
}

const int N = 2e5+1;

int cona[N];
int conb[N];
int n,m;
vector<int> adj[N];
bool del[N];
string s;

void solve(){
    cin >> n >> m;
    cin >> s;
    s = "$"+s;
    RE(i,m){
      int a,b;
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
      if(a == b){
        if(s[a] == 'A')cona[a]++;
        else conb[a]++;
      }
      else{
        if(s[a] == 'A')cona[b]++;
        else conb[b]++;
        if(s[b] == 'A')cona[a]++;
        else conb[a]++;
      }
    }
    queue<int> q;
    RE(i,n){
      //cout << cona[i] << " " << conb[i] << endl;
      if(cona[i]*conb[i])continue;
      q.push(i);
      del[i] = 1;
    }
    int delss = 0;
    while(!q.empty()){
      int u = q.front();
      //cout << u << endl;
      q.pop();
      delss++;
      for(int v:adj[u]){
        if(del[v])continue;
        if(s[u] == 'A')cona[v]--;
        else conb[v]--;
        //cout << v << " " << cona[v] << " " << conb[v] << endl;
        if(cona[v]*conb[v])continue;
        q.push(v);
        del[v] = 1;
      }
    }
    if(delss == n){
      cout << "No";
    }
    else{
      cout << "Yes";
    }
}

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen(".in","r",stdin);freopen(".out","w",stdout);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
