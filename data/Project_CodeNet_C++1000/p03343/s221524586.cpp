
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int n;
int k;
int nQuery;
int vs[2000+10];
// int ms[2000+10][2010];
// int is[2000+10][2010];

struct K {
  vector<int> sorted;
  int used;
};
bool operator>(const K& k1, const K& k2) {
  return k1.sorted[k1.used] > k2.sorted[k2.used];
}

int main(void) {
  scanf("%d%d%d", &n, &k, &nQuery);
  set<int> ss;
  ss.insert(0);
  REP(i, n) {
    scanf("%d", &vs[i]);
    ss.insert(vs[i]);
  }

  int res = 2000000000;
  for(int v : ss) {
    priority_queue<K, vector<K>, greater<K> > q;
    { // init
      int lastOmit = -1;
      vector<int> sorted;
      REP(i, n) {
        if(vs[i] <= v) {
          if((int)sorted.size() >= k) {
            K r;
            r.used = 0;
            sort(sorted.begin(), sorted.end());
            r.sorted = sorted;
            q.push(r);
          }
          lastOmit = i;
          sorted.clear();
        } else {
          sorted.push_back(vs[i]);
        }
      }
      K r;
      r.used = 0;
      if((int)sorted.size() >= k) {
        sort(sorted.begin(), sorted.end());
        r.sorted = sorted;
        q.push(r);
      }
    }

    int maxi = -1;
    int mini = 2000000000;
    int cnt = 0;
    // cerr << endl;
    while(cnt < nQuery && !q.empty()) {
      K cur = q.top(); q.pop();
      int curV = cur.sorted[cur.used];
      // cerr << ">" << curV << endl;
      maxi = max(maxi, curV);
      mini = min(mini, curV);
      cur.used++;
      if((int)cur.sorted.size() - cur.used >= k) {
        q.push(cur);
      }
      ++cnt;
    }
    // cerr << v << " " << mini << " " << maxi << " " << cnt << endl;
    if(cnt == nQuery) {
      int cur = maxi - mini;
      res = min(res, cur);
    } else {
      break;
    }
  }

  printf("%d\n", res);
  
  return 0;
}
