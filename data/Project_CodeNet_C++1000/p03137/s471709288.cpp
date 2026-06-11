#include<bits/stdc++.h>
using namespace std;

int n,m;
int x[100000];
int d[100000];

signed main() {
  cin >> n >> m;
  for(int i=0; i<m; i++) cin >> x[i];

  if( n>=m ) {puts("0"); return 0;}

  sort(x, x+m);

  priority_queue<pair<int, int>> pq;
  int sum = 0;
  for(int i=0; i<m-1; i++) {
    d[i] = x[i+1] - x[i];
    sum += d[i];
    pq.emplace(d[i], i);
  }

  cerr << sum << endl;

  while(n>1) {
    auto p = pq.top(); pq.pop();
    sum -= p.first;
    n -= 1;
  }

  cout << sum << endl;
}
