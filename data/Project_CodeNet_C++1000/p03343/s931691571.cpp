#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using P = pair<int,int>;
const int INF = 1e9;

int main(){
  int n, k, q;
  cin >> n >> k >> q;
  int a[n];
  P b[n];
  rep(i,n) {
    cin >> a[i];
    b[i] = P(a[i],i);
  }
  sort(b,b+n);
  vector<int> v;
  int ans = INF;
  v.push_back(-1); v.push_back(n);
  rep(i,n) {
    vector<vector<int>> p(v.size()-1);
    vector<int> r;
    rep(j,v.size()-1) {
      for(int l = v[j]+1; l < v[j+1]; l++) p[j].push_back(a[l]);
      sort(p[j].begin(),p[j].end());
      rep(l,p[j].size()-k+1) r.push_back(p[j][l]);
    }
    sort(r.begin(),r.end());
    if(r.size() >= q) ans = min(ans,r[q-1]-r[0]);
    v.push_back(b[i].second);
    sort(v.begin(),v.end());
  }
  cout << ans << endl;
  return 0;
}