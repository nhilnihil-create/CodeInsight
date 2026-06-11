#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,0,n) cin >> a[i];
  ll sum = a[0],xum = a[0],ans = 0;
  int r = 0;
  rep(l,0,n){
    while(r < n && sum == xum){
      r++;
      sum += a[r];
      xum ^= a[r];
    }
    ans += r-l;
    if(l == r) r++;
    sum -= a[l];
    xum ^= a[l];
  }
  cout << ans << endl;
}