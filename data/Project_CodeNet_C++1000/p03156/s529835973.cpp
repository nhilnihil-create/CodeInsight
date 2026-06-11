#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main(){
  int n,a,b; cin >> n >> a >> b;
  int aa = 0, bb = 0, cc = 0;
  for(int i = 0; i < n; i++){
    int now; cin >> now;
    if(now <= a) aa++;
    else if(a < now && now <= b) bb++;
    else cc++;
  }
  int ans = min({aa,bb,cc});
  cout << ans << endl;
  return 0;
}
