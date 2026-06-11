#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;


//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
int n;
VVI edge(201010,VI());
bool visited[201010];
ll width;
ll dfs(int node){
  visited[node] = true;

  priority_queue<ll> que;
  que.push(0);
  que.push(0);
  rep(i,edge[node].size()){
    if(visited[edge[node][i]] == true) continue;
    que.push( dfs(edge[node][i]) );
  }
  ll first = que.top();
  que.pop();
  ll second = que.top();
  width = max(width,first+second);

  return first+1;

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  dfs(0);
  if(width % 3 != 1){
    cout << "First" << "\n";
  }else{
    cout << "Second" << "\n";
  }
  return 0;
}
