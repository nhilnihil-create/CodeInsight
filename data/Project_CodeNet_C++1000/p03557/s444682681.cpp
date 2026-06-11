#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
typedef long long ll;

using ipair = pair<int, int>;

ll INF = 1e16+7;
ll mod = 1e9+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

int main(){
  ll N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  ll ans = 0LL;

  rep(i, N){
    // B[i]未満の個数
    ll a_b = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    // B[i]より大きい個数
    ll b_c = C.end() - upper_bound(C.begin(), C.end(), B[i]);
    ans += a_b * b_c;
  }
  cout << ans << endl;
  return 0;
}
