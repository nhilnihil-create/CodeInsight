// clang-format

#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;

using lli = long long int;
vector<int> e[200005];
int n;
pair<int,int> last(int u){
  queue<pair<int,int>> que;
  que.push(make_pair(u, 1));
  vector<int> vis(n);
  pair<int,int> p;
  vis[u] = true;
  while(!que.empty()){
    p = que.front();
    que.pop();
    //cout << p.first << " ";
    for(auto s:e[p.first]){
      if(vis[s]) continue;
      que.push(make_pair(s, p.second+1));
      vis[s] = true;
    }
  }
  //cout << endl;
  return p;
}
void solve(long long N, std::vector<long long> a, std::vector<long long> b) {
  n = N;
  rep(i, N-1) a[i]--,b[i]--, e[a[i]].push_back(b[i]), e[b[i]].push_back(a[i]);
  auto f = last(0);
  auto g = last(f.first);
  if(g.second % 3 == 2){
    cout << "Second"<<endl;
  }else {
    cout << "First"<<endl;
  }
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N - 1);
  std::vector<long long> b(N - 1);
  for (int i = 0; i < N - 1; i++) {
    scanf("%lld", &a[i]);
    scanf("%lld", &b[i]);
  }
  solve(N, std::move(a), std::move(b));
  return 0;
}
