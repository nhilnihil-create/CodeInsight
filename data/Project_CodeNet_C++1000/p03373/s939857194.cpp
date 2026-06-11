#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<ll,int> p;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;

  int ans1 = a * x + b * y;
  int ans2 = [&]{
    int res = min(x, y) * c * 2;
    if (x > y) {
      res += (x - y) * a;
    } else {
      res += (y - x) * b;
    }
    return res;
  }();
  int ans3 = c * max(x, y) * 2;

  ans = min(ans1, min(ans2, ans3));
  cout << ans << endl;
}
