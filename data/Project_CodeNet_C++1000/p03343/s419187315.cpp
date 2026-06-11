#include <bits/stdc++.h>
using namespace std;
 
int a[2005];
 
int main() {
  int n, k, q;
  cin >> n >> k >> q;
  for (int ni = 0; ni < n; ni++) {
    cin >> a[ni];
  }
  int answer = 1000000000;
  for (int ni = 0; ni < n; ni++) {
    vector<int> candidates;
    vector<int> buffer;
    for (int nj = 0; nj < n; nj++) {
      if (a[nj] < a[ni]) {
        if (buffer.size() >= k) {
          sort(buffer.begin(), buffer.end());
          candidates.insert(candidates.end(), buffer.begin(), buffer.begin() + (buffer.size() - k + 1));
        }
        buffer.clear();
      } else {
        buffer.push_back(a[nj]);
      }
    }
    if (buffer.size() >= k) {
      sort(buffer.begin(), buffer.end());
      candidates.insert(candidates.end(), buffer.begin(), buffer.begin() + (buffer.size() - k + 1));
    }
    sort(candidates.begin(), candidates.end());
    if (candidates.size() >= q) {
      answer = min(answer, candidates[q - 1] - candidates[0]);
    }
  }
  cout << answer << endl;
  return 0;
}