#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define erep(i,a,n) for(int i = a;i<=n;i++)
typedef long long ll;
#define int long long
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define P = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

signed main(){
  int n;
  cin >> n;
  vvint to(n);
  rep(i,0,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vint C(n);
  rep(i,0,n) cin >> C[i];
  sort(C.rbegin(),C.rend());
  int sum = 0;
  rep(i,0,n) sum += C[i];
  queue<int> que;
  vint ans(n);
  vbool seen(n);
  que.push(0);
  int cur = 0;
  while(!que.empty()){
    int v = que.front();
    que.pop();
    seen[v] = true;
    ans[v] = C[cur];
    cur++;
    for(auto p:to[v]){
      if(seen[p]) continue;
      que.push(p);
    }
  }
  cout << sum - C[0] << endl;
  rep(i,0,n) cout << ans[i] << " ";
}