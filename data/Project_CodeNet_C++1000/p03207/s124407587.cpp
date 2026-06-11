#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int n; cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  sort(p.begin(), p.end());
  int ans = 0;
  rep(i,n-1){
    ans += p[i];
  }
  ans += p[n-1] / 2;
  cout << ans << endl;
  return 0;
}
