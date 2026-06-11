#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  ll n,sum = 0,ans = 0;
  cin >> n;
  vector<int>a(n);
  vector<int>b(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  rep(i,0,n){
    a[i] -= b[i];
    sum += a[i];
  }
  if(sum < 0){
    cout << -1 << endl;
    return 0;
  }
  sum = 0;
  sort(a.begin(),a.end());
  rep(i,0,n){
    if(a[i] >= 0) break;
    sum += a[i];
    ans++;
  }
  if(a[0] >= 0){
    cout << 0 << endl;
    return 0;
  }
  reverse(a.begin(),a.end());
  rep(i,0,n){
    ans++;
    sum += a[i];
    if(sum >= 0) break;
  }
  cout << ans << endl;
}