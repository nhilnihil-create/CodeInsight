#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, m;
  cin >> n >> m;
  vi a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  deque<int> que;
  rep(i,n) que.push_back(a[i]);
    
  vector<pair<int,int>> cb(m);
  rep(i,m) cin >> cb[i].second >> cb[i].first;
  sort(cb.rbegin(),cb.rend());
  
  rep(i,m){
    rep(j,cb[i].second){
      if(que.front() >= cb[i].first) break;
      que.pop_front();
      que.push_back(cb[i].first);
    }
  }
  ll ans = 0;
  rep(i,n){
    ans += que.front();
    que.pop_front();
  }
  cout << ans << endl;
}
