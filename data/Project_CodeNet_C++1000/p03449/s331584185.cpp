#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  rep(i, n){
    int in;
    cin >> in;
    a.at(0).at(i) = in;
  }
  int sum = 0;
  rep(i, n){
    int in;
    cin >> in;
    sum += in;
    a.at(1).at(i) = in;
  }
  int ans = 0, now = 0;
  rep(i, n){
    now += a.at(0).at(i);
    int add = now + sum;
    ans = max(ans, add);
    sum -= a.at(1).at(i);
  }
  cout << ans << endl;
  return 0;
}