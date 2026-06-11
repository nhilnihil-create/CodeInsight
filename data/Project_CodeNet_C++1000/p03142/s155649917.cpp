#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

typedef pair<int, int> p_ii;

int main() {
  int N, M; cin >> N >> M;
  vector<int> adj[N], radj[N];
  int num_to[N] = {};
  rep(i,N-1+M) {
    int A, B; cin >> A >> B; A--; B--;
    adj[A].push_back(B);
    radj[B].push_back(A);
    num_to[B]++;
  }

  vector<p_ii> topo;
  queue<int> q; rep(i,N) if (num_to[i]==0) q.push(i);
  int count = 0;
  while (!q.empty()) {
    int now = q.front(); q.pop();
    topo.push_back(make_pair(now,count));
    count++;
    for (auto x: adj[now]) {
      num_to[x]--;
      if (num_to[x]==0) q.push(x);
    }
  }
  sort(topo.begin(), topo.end(), [](const p_ii &x, const p_ii &y){return x.first<y.first;});

  rep(i,N) {
    int result = -1;
    for (auto x: radj[i]) {
      if (result==-1||topo[result].second<topo[x].second) {
        result = x;
      }
    }
    cout << result+1 << endl;
  }
  // rep(i,N) cout << topo[i].first << "->" << topo[i].second << endl;
  return 0;
}