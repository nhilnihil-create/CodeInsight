#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int gcd(int lhs, int rhs)
{
  int a = max(lhs, rhs);
  int b = min(lhs, rhs);
  while (a % b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return b;
}

int main() {
  int N;
  cin >> N;

  deque<int> q;
  rep(i,0,N-1) {
    int a;
    cin >> a;
    q.push_back(a);
  }

  while (1 < q.size()) {
    int a = q.front(); q.pop_front();
    int b = q.front(); q.pop_front();
    int c = gcd(a, b);
    q.push_front(c);
  }

  cout << q.front() << endl;
  return 0;
}
