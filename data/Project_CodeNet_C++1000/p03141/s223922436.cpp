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
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  vector<tuple<ll, ll, ll>> point(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
  }
  rep(i, n) {
    ll t = a[i] + b[i];
    point[i] = tie(t, a[i], b[i]);
  }
  sort(point.rbegin(), point.rend());
  ll takahashi = 0, aoki = 0;
  rep(i, n) {
    int x, y, z;
    tie(x, y, z) = point[i];
    if(i % 2) aoki += z;
    else takahashi += y;
  }
  cout << takahashi - aoki << endl;
}