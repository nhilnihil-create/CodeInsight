#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n, m;
  cin >> n >> m;
  vi x(m), y(m-1);
  rep(i,m) cin >> x.at(i);
  sort(x.begin(),x.end());
  rep(i,m-1) y.at(i) = abs(x.at(i+1) - x.at(i));
  sort(y.begin(),y.end());
  int ans = 0;
  rep(i,m-n) ans += y.at(i);
  cout << ans << endl;
  return 0;
}
