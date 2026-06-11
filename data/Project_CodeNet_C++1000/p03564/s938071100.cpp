#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  ll n,k;cin>>n>>k;

  int ans=1;
  rep(i, n) {
    int tmp_bai = ans*2;
    int tmp_k = ans+k;
    if (tmp_bai < tmp_k) {
      ans = ans*2;
    } else {
      ans = ans+k;
    }
  }
  cout << ans << endl;
  return 0;
}