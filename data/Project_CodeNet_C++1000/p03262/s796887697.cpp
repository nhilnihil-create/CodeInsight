#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int gcd(int a, int b) {
  int r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main() {
  int N, X;
  cin >> N >> X;

  priority_queue<int> q; int x;
  rep(i,0,N-1) {
    cin >> x;
    q.push(abs(X - x));
  }

  while (1 < q.size()) {
    int a = q.top(); q.pop();
    int b = q.top(); q.pop();
    int n = gcd(a, b);
    q.push(n);
  }

  cout << q.top() << endl;
  return 0;
}
