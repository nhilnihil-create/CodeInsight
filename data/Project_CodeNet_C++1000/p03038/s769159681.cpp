#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int n,m; cin >> n >> m;
  priority_queue<P> q;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    q.push(P(a,1));
  }

  for(int i = 0; i < m; i++){
    int b,c; cin >> b >> c;
    q.push(P(c,b));
  }
  ll ans = 0;
  for(int i = 0; i < n; i++){
    P p = q.top(); q.pop();
    ans += p.first;
    p.second--;
    if(p.second != 0) q.push(p);
  }
  cout << ans << endl;
  return 0;
}
