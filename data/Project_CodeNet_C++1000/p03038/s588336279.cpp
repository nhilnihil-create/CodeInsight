#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, m;
  cin >> n >> m;
  map<ll,int> mp;
  rep(i,n) {
    int b;
    cin >> b;
    mp[-1*b]++;
  }
  rep(i,m) {
    int x, y;
    cin >> x >> y;
    mp[-1*y]+=x;
  }
  ll ans=0;
  int num=n;
  for(auto p : mp) {
    ans += -1*p.first*min(p.second,num);
    num -= p.second;
    if(num<=0) {
      cout << ans << endl;
      return 0;
    }
  }
}