#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, m;
  cin >> n >> m;
  priority_queue<pair<int, int>> que;
  vi a(n);
  rep(i,n) cin >> a[i];
  rep(i,n) que.push(make_pair(a[i], 1));
  rep(i,m){
    int b, c;
    cin >> b >> c;
    que.push(make_pair(c, b));
  }
  ll ans = 0;
  rep(i,n){
    auto v = que.top(); que.pop();
    if(v.second > 1){
      v.second --;
      que.push(v);
    }
    ans += v.first;
  }
  cout << ans << endl;
}
