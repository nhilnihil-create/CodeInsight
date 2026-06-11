#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);


int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(2,vector<int>(n));
  rep(i,2)rep(j,n) cin >> a[i][j];
  int sum = 0;
  int ans = -1;
  rep(i,n){
    for(int j = 0; j <= i; ++j){
      sum+=a[0][j];
    }
    for(int j = i; j < n; ++j){
      sum+=a[1][j];
    }
    ans=max(ans,sum);
    sum=0;
  } 
  cout << ans << endl;
  return 0;
}