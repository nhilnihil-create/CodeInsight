#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int n, k, ans;
int v[50];

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  for (int i = min(k/2, n); i <= min(k, n); i++) {  // 取り出す数
    for (int l = 0; l <= i; l++) {  // 左から取り出す数
      int r = i - l;
      priority_queue<int, vector<int>, greater<int> > pq;
      int sm = 0;
      for (int j = 0; j < l; j++) {
        sm += v[j];
        pq.push(v[j]);
      }
      for (int j = 0; j < r; j++) {
        sm += v[n-j-1];
        pq.push(v[n-j-1]);
      }
      for (int j = 0; j < min(i, k-i); j++) {
        if (pq.top() >= 0) break;
        sm -= pq.top();
        pq.pop();
      }
      ans = max(ans, sm);
    }
  }
  
  cout << ans << endl;
  return 0;
}