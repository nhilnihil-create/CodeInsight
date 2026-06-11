#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <fstream>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h,w,n;
  cin>>h>>w>>n;
  pair<int, int> p[n];
  int ans = h;
  rep(i,n) cin>>p[i].first>>p[i].second;
  sort(p, p + n);
  int k = 1;
  rep(i,n) {
    if(p[i].first == p[i].second + k - 1) {
      k++;
    } else if(p[i].first >= p[i].second + k) {
      ans = min(ans, p[i].first - 1);
    }
  }
  cout << ans << endl;

  return 0;

}
