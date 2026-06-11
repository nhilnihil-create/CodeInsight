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
vector<int> d;
bool loop = false;

void dfs(int n=0, int p=-1) {
  for (auto x: adj[n]) {
    if (x==p) continue;
    if (d[x]==d[n]) loop = true;
    if (d[x]==-1) {
      d[x] = !d[n];
      dfs(x,n);
    }
  }
}

int main() {
  ll N, M; cin >> N >> M;
  adj.resize(N); d.resize(N,-1); d[0] = 0;
  rep(i,M) {
    int A, B; cin >> A >> B; A--; B--;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }
  dfs();

  ll result = 0;
  if (loop) result = N*(N-1)/2 - M;
  else {
    ll odd = 0, even = 0;
    rep(i,N) {
      if (d[i]%2) odd++;
      else even++;
    }
    result = odd*even - M;
  }
  // debug(d.begin(),d.end());
  cout << result << endl;
  return 0;
}