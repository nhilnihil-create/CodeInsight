#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  priority_queue<int> que;
  queue<int> need;
  int answer = 0;
  for (int i = 0; i < n; i++) {
    if(a[i] > b[i]) que.push(a[i] - b[i]);
    else if(a[i] < b[i]) {
      need.push(b[i] - a[i]);
      answer++;
    }
  }

  while(true) {
    int x = que.top();
    que.pop();
    int sub = 0;

    bool flag = false;
    while(!need.empty()) {
      flag = true;
      sub = need.front();
      need.pop();
      if(sub >= x) {
        sub = sub - x;
        need.push(sub);
        break;
      } else {  
        x -= sub;
      }
    }

    if(flag) answer++;
    if(!need.empty() && que.empty()) {
      answer = -1;
      break;
    } else if(need.empty()) {
      break;
    }
  }
  cout << answer << "\n";
  return 0;
}
