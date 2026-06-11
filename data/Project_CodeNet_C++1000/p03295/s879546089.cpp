#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> p(m);
  rep(i,m){
    cin >> p[i].second >> p[i].first;
  }
  sort(p.begin(),p.end());
  int ans=0;
  int now=0;
  for(pair<int,int> q:p){
    if(q.second>=now) {
      ans++;
      now=q.first;
    }
  }
  cout << ans << endl;
}