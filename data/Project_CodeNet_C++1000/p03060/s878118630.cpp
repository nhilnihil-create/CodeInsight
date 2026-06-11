#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  int ans = 0;
  rep(i,n){
    if(a[i] - b[i] > 0){
      ans += a[i] - b[i];
    }
  }
  cout << ans;
  return 0;
}


