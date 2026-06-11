#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int INF = 1001001;

int main(){
  int n, m, a, b;
  cin >> n >> m;
  vector<P> req(m);
  for(int i=0; i<m; ++i){
    cin >> a >> b;
    --a; --b;
    req[i] = make_pair(a,b);
  }
  sort(req.begin(),req.end());
  int minb = INF;
  int x = 0;
  int ans = 0;
  for(int i=0; i<n-1; ++i){
    for(int j=x; j<m; ++j){
      //cout << j << "req: " << req[j].first << '&' << req[j].second << endl;
      if(req[j].first != i) break;
      minb = min(minb, req[j].second);
      ++x;
    }
    //cout << i << ':' << minb << endl;
    if(minb == i+1){
      ++ans;
      //cout << "ans++" << endl;
      minb = INF;
    }
  }
  cout << ans << endl;
}