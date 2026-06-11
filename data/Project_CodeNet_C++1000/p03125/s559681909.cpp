#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
const ll mod = 1000000007;
int main()
{
  int a, b;
  cin >> a >> b;
  int ans;
  if (b%a==0) ans = a+b;
  else ans = b-a;
  cout << ans << endl;
  return 0;
}