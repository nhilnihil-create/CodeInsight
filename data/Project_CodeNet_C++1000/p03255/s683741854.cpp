#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;

ll f(const vector<ll> &x, const int skip, const ll X) {
  ll work = 0LL;
  const int N = x.size();
  for(int i = 0; i < N; i++) {
    int a = i / skip;
    if(a == 0) work += X + 5LL * x[i];
    else {
      work += (ll)(3 + 2 * a) * x[i];
    }
  }
  //  cout << skip << "," << work << endl;                                     
  return work;
}

int main() {
  int N;    ll X ; cin>>N>>X;
  vector<ll> x(N);
  REP(i,N) cin>>x[i];
  ll ans = 1LL<<62;

  reverse(x.begin(), x.end());
  int left = 1, right = N;
  while(left < right) {
    int oleft = left, oright = right;
    int s1 = (left * 2 + right) / 3;
    int s2 = (left + right * 2) / 3;
    ll w1 = f(x, s1, X);
    ll w2 = f(x, s2, X);
    if(w1 < w2) {
      right = s2;
    } else {
      left = s1;
    }
    ans = min(ans, min(w1, w2));
    if(oleft ==	left &&	oright == right) break;
    //    cout << skip << " " << work << " " << ans << endl;                   
  }
  cout << ans + (ll)N * X << endl;
  return 0;
}



