#include <bits/stdc++.h>
using namespace std;

using PP = pair<long, long>;

int n, k;
PP p[100000];
vector<int> v[100000];
int used[100000];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    p[i] = PP(a, b);
    v[a].push_back(b);
  }
  
  sort(p, p + n, [](PP a, PP b) { return a.second > b.second; });
  for (int j = 0; j < n; ++j) {
    sort(v[j].begin(), v[j].end(), greater<int>());
  }
  
  long sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += p[i].second;
    ++used[p[i].first];
  }
  
  long cnt = 0;
  for (int j = 0; j < n; ++j) {
    cnt += used[j] > 0;
  }
  
  vector<int> rem;
  for (int j = 0; j < n; ++j) {
    if (used[j]) continue;
    if (v[j].empty()) continue;
    rem.push_back(v[j].front());
  }
  sort(rem.begin(), rem.end(), greater<int>());
  
  long mx = sum + cnt * cnt;
  int idx = 0;
  for (int i = k - 1; i >= 0; --i) {
    if (idx >= rem.size()) break;
    int a = p[i].first;
    int b = p[i].second;
    if (used[a] == 1) continue;
    --used[a];
    
    sum -= b;
    sum += rem[idx];
    ++cnt;
    ++idx;
    mx = max(mx, sum + cnt * cnt);
  }
  cout << mx << endl;
}