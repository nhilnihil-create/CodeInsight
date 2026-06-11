#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<vector<int>> adj;
vector<int> v, c;

int dfs(int n=0, int p=-1, int pos=0) {
  v[n] = c[pos]; pos++;
  for (auto x: adj[n]) {
    if (x!=p) pos = dfs(x,n,pos);
  }
  return pos;
}

int main() {
  int N; cin >> N;
  adj.resize(N); v.resize(N); c.resize(N);
  rep(i,N-1) {
    int a, b; cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  rep(i,N) cin >> c[i]; sort(c.begin(),c.end(),greater<int>());
  dfs();

  ll result = 0; repr(i,1,N) result += v[i];
  cout << result << endl;
  rep(i,N) cout << v[i] << " "; cout << endl;
  return 0;
}