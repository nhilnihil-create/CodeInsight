#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <tuple>

#define rep(i,n) for(ll i=0;i<n;i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

using Graph = vector<vector<ll>>;
//	std::cout<<std::fixed<<std::setprecision(10);

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  vector<ll> ones(60, 0); // ones[i] Aの右から 第i+1bit にある 1 の数
  rep(i, 60) {
    rep(j, N) {
      if(A[j]%2==1) ones[i]++;
      A[j] = A[j] >> 1;
    }
  }

  // rep(i, 10) {
  //   cout << ones[i] << ' ';
  // }
  // cout << endl;

  ll X = 0;
  ll ans = 0;
  for(int i=59; i>=0; i--) {
    if(ones[i]*2>N) {
      // この桁は0でよい。
      ans = (ans<<1) + ones[i];
    } else {
      // この桁を1にしたい
      if(X+(1LL<<i) > K) {
        // 上限を超えるので 1 にできない。
        ans = (ans<<1) + ones[i];
      } else {
        X += (1LL<<i);
        ans = (ans<<1) + (N-ones[i]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
