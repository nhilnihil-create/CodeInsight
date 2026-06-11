//Written by Zhu Zeqi
//Come on,baby
//Hack,please
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
//orz yht
using namespace std;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    int n;
  cin >> n;
  vector<long long> d(n);
  vector<int> weight(n, 1);
  map<long long,int> mp;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    mp[d[i]] = i;
  }
  vector<pair<int,int> > res;
  for (int itt = 0; itt < n - 1; itt++) {
    auto it = mp.rbegin();
    int i = it->second;
    long long want = d[i] - (n - weight[i]) + weight[i];
    if (mp.find(want) == mp.end() || mp[want] == i) {
      cout << -1 << '\n';
      return 0;
    }
    int j = mp[want];
    res.emplace_back(i, j);
    weight[j] += weight[i];
    mp.erase(--mp.end());
  }
  vector<long long> real_dist(n, -1);
  real_dist[0] = 0;
  vector<vector<int> > g(n);
  for (auto &p : res) {
    g[p.first].push_back(p.second);
    g[p.second].push_back(p.first);
  }
  vector<int> que(1, 0);
  for (int b = 0; b < (int) que.size(); b++) {
    for (int j : g[que[b]]) {
      if (real_dist[j] == -1) {
        que.push_back(j);
        real_dist[j] = real_dist[que[b]] + 1;
      }
    }
  }
  if (accumulate(real_dist.begin(), real_dist.end(), 0LL) != d[0]) {
    cout << -1 << '\n';
    return 0;
  }
  for (auto &p : res) {
    cout << p.first + 1 << " " << p.second + 1 << '\n';
  }
	return 0;
}