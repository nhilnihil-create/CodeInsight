#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  stack<int> ans;
  for (int &e : v) cin >> e;
  
  while (v.size() > 0) {
    int p = -1;
    for (int i = 0; i < N; i++) {
      if (v[i] == i+1) p = i;
    }
    if (p < 0) {
      cout << -1 << endl;
      return 0;
    }
    ans.push(v[p]);
    v.erase(v.begin()+p);
    N--;
  }
  
  while (ans.size() > 0) {
    cout << ans.top() << endl;
    ans.pop();
  }
}