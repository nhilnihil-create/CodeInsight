#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};


int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  ll ans = 0;
  for(int k = 0; k < 30; k++) {
    ll T = 1 << k;
    vector<ll> A_(N), B_(N);
    for (int i = 0; i < N; i++) {
      A_[i] = A[i] % (2 * T);
      B_[i] = B[i] % (2 * T);
    }
    sort(B_.begin(), B_.end());
    ll sum = 0;
    for (int i = 0; i < N; i++) {
      ll a = A_[i];
      ll k1 = lower_bound(B_.begin(), B_.end(), 2LL * T - a) - lower_bound(B_.begin(), B_.end(), 1LL * T - a);
      ll k2 = lower_bound(B_.begin(), B_.end(), 4LL * T - a) - lower_bound(B_.begin(), B_.end(), 3LL * T - a);
      sum += k1 + k2;
    }
    if (sum & 1 == 1) {
      ans |= T;
    }
  }
  cout << ans << endl;
  return 0;
}