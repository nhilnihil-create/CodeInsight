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
  int n, k;
  cin >> n >> k;
  vector<ll> cnt(k);
  for (int i = 1; i <= n; ++i) {
    cnt[i % k]++;
  }
  ll ans = 0;
  rep(a, k) {
    int b = k - a;
    int c = k - a;
    if((a + b) % k == 0 && (b + c) % k == 0) {
      ans += cnt[a] * cnt[b % k] * cnt[c % k];
    }
  }
  cout << ans << endl;
}
