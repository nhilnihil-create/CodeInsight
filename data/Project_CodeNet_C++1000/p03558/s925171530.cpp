#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef pair<int, int> P;

int main(){
  int k; cin >> k;
  int d[k]; rep(i, k) d[i] = INT_MAX;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, 1));
  d[1] = 0;
  while(!que.empty()){
    P p = que.top(); que.pop();
    if(p.first > d[p.second]) continue;
    int n = (p.second+1) % k;
    if(d[n] > d[p.second] + 1){
      d[n] = d[p.second] + 1;
      que.push(P(d[n], n));
    }
    int m = p.second * 10 % k;
    if(d[m] > d[p.second]){
      d[m] = d[p.second];
      que.push(P(d[m], m));
    }
  }
  cout << d[0] + 1 << endl;
}