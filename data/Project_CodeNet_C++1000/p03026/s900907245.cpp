#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};

int main() {
   ll n; cin >> n;
   vvl G(n);
   rep(i,n-1){
       ll a,b; cin >> a >> b;
       a--; b--;
       G[a].push_back(b);
       G[b].push_back(a);
   }
   vl c(n);
   rep(i,n) cin >> c[i];
   sort(all(c));
   ll sum = 0;
   rep(i,n-1) sum += c[i];
   cout << sum << endl;
   queue<ll> q;
   q.push(0);
   vl ans(n,-1);
   ans[0] = c.back(); c.pop_back();
   while(!q.empty()){
       ll u = q.front(); q.pop();
       for(auto v : G[u]){
           if(ans[v] != -1) continue;
           ans[v] = c.back(); c.pop_back();
           q.push(v);
       }
   }
   rep(i,n) cout << ans[i] << " ";
}
