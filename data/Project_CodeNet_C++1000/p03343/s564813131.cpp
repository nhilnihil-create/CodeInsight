#include <bits/stdc++.h>
using namespace std;

long long n, k, q;
vector<long long> a;

long long solve();

int main() {
  cin >> n >> k >> q;
  a.resize(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long ans = (long long)1e16;
  for(int i = 0; i < n; ++i) {
    long long minnum = a[i];
    vector<long long> now;
    for(int id = 0; id < n; ++id) {
      priority_queue<long long, vector<long long>,
                     greater<long long>>
          pq;
      while(id < n && a[id] >= minnum) pq.push(a[id++]);
      while(pq.size() >= k) {
        now.push_back(pq.top());
        pq.pop();
      }
    }
    if(now.size() < q) continue;
    sort(now.begin(), now.end());
    ans = min(ans, now[q - 1] - minnum);
  }
  return ans;
}
