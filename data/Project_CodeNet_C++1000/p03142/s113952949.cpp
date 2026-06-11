#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
LL p = 1000000007ll;

int main(void)
{
  LL n,m;
  cin >> n >> m;
  vector<set<LL> > parent(n+1);
  vector<set<LL> > child(n+1);
  REP(i,n+m-1) {
    LL a,b;
    cin >> a >> b;
    parent[b].insert(a);
    child[a].insert(b);
  }
  vector<LL> answer(n+1);
  queue<LL> q;
  FOR(i,1,n+1) {
    if(parent[i].size()==0) {
      q.push(i);
      answer[i]=0;
    }
  }
  while(!q.empty()) {
    LL p = q.front();
    q.pop();
    for(LL c:child[p]) {
      parent[c].erase(p);
      if(parent[c].size()==0) {
        q.push(c);
        answer[c]=p;
      }
    }
  }
  FOR(i,1,n+1) cout << answer[i] << endl;
  return 0;
}
