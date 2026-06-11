#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  
  int n;
  cin >> n;
  priority_queue<ll> plus;
  vector<ll> minus;
  vector<ll> a(n), b(n);
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n) cin >> b[i];
  rep(i, n) {
    ll cur = a[i] - b[i];
    if(cur > 0) plus.push(cur);
    else if(cur < 0) minus.push_back(-cur);
  }
  ll ans = minus.size();
  ll cur = 0;

  rep(i, minus.size()) {

    while(cur < minus[i]) {
      if(plus.empty()){
        puts("-1");
        return 0;
      }
      ll t = plus.top(); plus.pop();
      ++ans;
      cur += t;
    }
    cur -= minus[i];
  }
  cout << ans << endl;
}