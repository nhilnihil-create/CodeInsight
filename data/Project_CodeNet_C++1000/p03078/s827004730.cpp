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
typedef pair<ll,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  vector<ll> ab;
  rep(i, x)rep(j, y) ab.push_back(a[i] + b[j]);
  sort(ab.rbegin(), ab.rend());
  ab.resize(k);

  vector<ll> abc;
  rep(i, ab.size())rep(j, z) abc.push_back(ab[i] + c[j]);
  sort(abc.rbegin(), abc.rend());
  rep(i, k) cout << abc[i] << endl;
}
