#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  ll a[n];
   map<ll,int> m; 
  rep(i,n) {
    cin >> a[i];
    m[a[i]]++;
  }
  sort(a,a+n,greater<ll>());
  int ans = 0;
  rep(i,n) {
    for(int j = 31; j >= 0; j--){
      ll c = (1<<j) - a[i];
      if(c == a[i]) {
        if(m[c] >= 2) {
          ans++;
          m[c] -= 2;
        }
      } else if(c > 0 && m[c] >= 1 && m[a[i]] >= 1) {
        ans++;
        m[c]--; m[a[i]]--;
        continue;
      }
    }
  }
  cout << ans << endl;
  return 0;
}