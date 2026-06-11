#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  if(a+b-1 > n || (ll)a*b < n){
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  int l = n - (a+b-1);
  int num = b;
  rrep(i, b) ans.push_back(i+1);
  rep2(i, 1, a){
    int nx = num + min(l, b-1) + 1;
    l -= min(l, b-1);
    // cerr << num+1 << " " << nx+1 << endl;
    rrep2(j, num+1, nx+1){
      ans.push_back(j);
    }
    num = nx;
  }
  rep(i, n){
    if(i != 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}