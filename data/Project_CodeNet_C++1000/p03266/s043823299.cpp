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
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> surplus(k);
  for (int i = 1; i <= n; ++i) {
    surplus[i % k]++;
  }
  ll ans = 0;
  for (int i = 0; i < k; ++i) {
    int a = i;
    int b = (k - a) % k;
    int c = (k - a) % k;
    if((b + c) % k == 0) {
      ans += surplus[a] * surplus[b] * surplus[c];
    }
  }
  cout << ans << endl;
}