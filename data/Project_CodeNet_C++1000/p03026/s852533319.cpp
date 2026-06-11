#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vi> to(n);
  rep(i,n-1){
    int a,b; cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vi c(n);
  int ans = 0;
  rep(i,n){
    cin >> c[i];
    ans += c[i];
  }
  sort(all(c),greater<int>());
  ans -= c[0];
  cout << ans << endl;
  vi node(n);
  queue<int> q;
  q.push(0);
  node[0] = c[0];
  int i = 1;
  while(!q.empty()){
    int now = q.front(); q.pop();
    for(int next : to[now]){
      if(0 < node[next]) continue;
      node[next] = c[i++];
      q.push(next);
    }
  }
  rep(i,n) cout << node[i] << " ";
  return 0;
}
