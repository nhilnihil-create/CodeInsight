#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define rep(i,n) for (int i=0; i<n;++i)
#define ALL(a)  (a).begin(),(a).end()
typedef long long ll;
using namespace std;
vector<int> T[10005]; 
int N;
ll c[10005], score[10005];
bool searched[10005];
queue<int> que;

int main() {
  INCANT;
  cin >> N;
  int u,v;
  rep(i, N-1) {
    cin >> u >> v;
    u--;v--;
    T[u].push_back(v);
    T[v].push_back(u);
  }
  ll sum=0ll;
  rep(i, N) {
    cin >> c[i];
    sum+=c[i];
  }
  sort(c, c+N, greater<ll>());
  rep(i, N) {
    if (T[i].size()==1) {
      searched[i] = true;
      que.push(i);
      break;
    }
  }
  int now=0;
  while(!que.empty()) {
    int k = que.front();
    que.pop();
    score[k] = c[now];
    now++;
    for (auto p: T[k]) {
      if (!searched[p]) {
        searched[p] = true;
        que.push(p);
      }
    }
  }
  cout << sum-c[0] << endl;
  rep(i, N) cout << score[i] << ' ';
  cout << endl;
  return 0;
}