#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  int a[n], b[n];
  priority_queue<P> pq;
  rep(i, n){
    cin >> a[i] >> b[i];
    pq.push(make_pair(a[i] + b[i], i));
  }
  ll as = 0, bs = 0;
  int cnt = 0;
  while(pq.size() > 0){
    if(cnt % 2 == 0) as += a[pq.top().second];
    else bs += b[pq.top().second];
    cnt++;
    pq.pop();
  }
  cout << as - bs << endl;
  return 0;
}
