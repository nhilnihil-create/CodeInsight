#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;

const int SIZE = 200000	+ 10;
int cnt[SIZE][2];

bool solve() {
  int N, M; cin>>N>>M;
  string s; cin>>s;
  vector<int> mark(N);
  vector<vector<int> > edges(N);
  REP(i,N) {
    mark[i] = (s[i] == 'A' ? 0 : 1);
  }
  REP(i,M) {
    int a, b; cin>>a>>b; a--; b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
    cnt[a][mark[b]]++;
    cnt[b][mark[a]]++;
  }
  deque<int> q;
  REP(i,N) {
    if(cnt[i][0] == 0 || cnt[i][1] == 0) q.push_back(i);
  }

  vector<bool> used(N, false);
  while(! q.empty()) {
    int cur = q.front();
    q.pop_front();
    //    cout << cur << "," << used[cur] << endl;                             
    if(used[cur]) continue;
    used[cur] =	true;
    REP(i, edges[cur].size()) {
      int to = edges[cur][i];
      cnt[to][mark[cur]]--;
      if(cnt[to][mark[cur]] == 0) {
	if(used[to] == false) q.push_back(to);
      } 
    }
  }
  REP(i,N) {
    //    cout << i << " " << used[i] << endl;                                 
    if(used[i] == false) return	true;
  }
  return false;
}

int main() {
  bool ans = solve();
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
