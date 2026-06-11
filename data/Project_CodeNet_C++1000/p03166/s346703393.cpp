// g++ -std=c++14

//Difficulty according to solve count during contest:
//A B C D H F E I G K L M N P S O Q R J U Z Y X T V W

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) (c.begin(),c.end())
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define int ll
int n, m;
vector<vector<int> > graph;
vector<int> visited;
vector<int> dp;
vector<int> v;
void topSort(int node){
  visited[node] = 1;
  for(auto &x: graph[node])
    if(!visited[x])
      topSort(x);
  visited[node] = 2;
  v.push_back(node);
}
void func(int node){
  for(auto &x: graph[node]){
    dp[x] = max(dp[x], dp[node] + 1);
  }
}
int32_t main(){ _
  cin >> n >> m;
  graph.resize(n + 1);
  visited.resize(n + 1, 0);
  dp.resize(n + 1, 0);
  for(int i = 0; i < m; i++){
      int x, y;
      cin >> x >> y;
      graph[x].push_back(y);
  }
  for(int i = 1; i <= n; i++)
    if(!visited[i])
      topSort(i);
  reverse(v.begin(), v.end());
  for(int i = 0; i < n; i++){
    func(v[i]);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++)
    ans = max(ans, dp[i]);
  cout << ans << endl;
}
