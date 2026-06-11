#include <bits/stdc++.h>
#include <set>
#include <numeric>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 


int solve() {
  int n; cin >> n;
  vector<int> v(n);
  vector<int> c(n);
  for (int i=0;i<n;++i) {
    cin >> v[i];
  }
  for (int i=0;i<n;++i) {
    cin >> c[i];
  }
  int ans=0;
  for (int i=0;i < n; ++i) {
    if (v[i]> c[i]){
      ans += v[i] - c[i];
    }
  }

  cout << ans << endl;

}


int main(){
  solve();
  return 0;
}