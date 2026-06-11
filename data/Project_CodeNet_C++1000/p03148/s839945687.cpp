#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs

const int MAXN = 100500;

int n, k;
vector<pair<int, int>> v;
int sz[MAXN];
int types = 0;
priority_queue < pair<int, int> > q;
long long ans;
long long curAns;

int main() { 
  scanf("%d %d", &n, &k);

  for (int i = 0; i < n; i++) {
    int t, d;
    scanf("%d %d", &t, &d);
    v.push_back(make_pair(d, t));
  }

  sort(all(v));
  reverse(all(v));

  for (int i = 0; i < k; i++) {
    int curD = v[i].first, curT = v[i].second;
    ans += curD;
    if (sz[curT] == 0) {
      types++;
    }
    sz[curT]++;
    q.push(make_pair(-curD, curT));
  }
  ans += 1ll * types * types;
  curAns = ans;

  for (int i = k; i < n; i++) {
    int curD = v[i].first, curT = v[i].second;  
    if (sz[curT] == 0) {
      bool found = false;
      while (!found && !q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        if (sz[p.second] == 1) {
          continue;
        }
        sz[p.second]--;
        curAns -= (-p.first);
        found = true;
        break;
      }
      if (found) {
        sz[curT]++;
        curAns -= (1ll * types * types);
        types++;
        curAns += (1ll * types * types);
        q.push(make_pair(-curD, curT));
        curAns += curD;
      }
    } else {
      bool found = false;
      while (!found && !q.empty()) {
        pair<int, int> p = q.top();
        if (sz[p.second] == 1) {
          q.pop();
          continue;
        }
        if (-p.first < curD) {
          found = true;
          sz[p.second]--;
          curAns -= (-p.first);
          found = true;
        }
        break;
      }
      if (found) {
        sz[curT]++;
        curAns += curD;
        q.push(make_pair(-curD, curT));
      }
    }
    ans = max(ans, curAns);
  }

  cout << ans << endl;

  return 0;
}
