#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vector<vi> to(n);
  vi a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;  b[i]--;
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
  }
  int ans = 0;
  rep(i,m){
    queue<int> q;  q.push(0);
    vi node(n,-1);
    while(!q.empty()){
      int now = q.front();  q.pop();
      for(int next : to[now]){
        if(now==a[i]&&next==b[i] || now==b[i]&&next==a[i]) continue;
        if(0 <= node[next]) continue;
        node[next] = now;
        q.push(next);
      }
    }
    bool ok = false;
    rep(j,n) if(node[j] == -1) ok = true;
    if(ok) ans++;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
