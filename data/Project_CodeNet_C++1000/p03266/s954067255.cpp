#include <iostream>
using namespace std;
#define ll long long

void solve(){
  ll N, K;
  cin >> N >> K;

  if ( K % 2 != 0 ) {
    ll res = 0;
    for (ll i = 1; i <= N; ++i) {
      if (i % K == 0) res++;
    }
    cout << res * res * res << endl;
  } else {
    ll res1 = 0;
    ll res2 = 0;
    for (ll i = 1; i <= N; ++i) {
      if ((i - (K / 2)) % K == 0) res1++;
      else if(i % K == 0) res2++;
    }

    cout << (res1 * res1 * res1) + (res2 * res2 * res2) << endl;
  }
}

int main(void) {
  solve();
  return 0;
}