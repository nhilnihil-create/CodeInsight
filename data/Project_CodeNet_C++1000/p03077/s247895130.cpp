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

int main(){
  ull n,a,b,c,d,e;
  cin >> n >> a >> b >> c >> d >> e;
  ull mn = min({a,b,c,d,e});
  ull ans = (n + mn - 1) / mn + 4;
  cout << ans << endl;
  return 0;
}
