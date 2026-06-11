#include "bits/stdc++.h"
typedef long long ll;
#define all(x) (x).begin(), (x).end()  // sortなどの引数を省略
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define max3(x, y, z) max(x, max(y, z))
#define min3(x, y, z) min(x, min(y, z))
using namespace std;
//#define int long long;

using namespace std;
signed main() {
  ll N;
  cin >> N;
  vector<ll> list0(N);
  rep(i, N) { cin >> list0[i]; }
  vector<ll> list1(N);
  rep(i, N) { cin >> list1[i]; }
  vector<ll> list2(N);
  rep(i, N) { cin >> list2[i]; }
  sort(all(list0));
  sort(all(list1));
  sort(all(list2));

  vector<ll> list3(N);
  vector<ll> list4(N+1);
  //中と下を先にくっつける
  rep(i, N) {
    auto it = upper_bound(all(list2),list1[i]);
    int index = it - list2.begin();
    list3[i] = N - index;
    //list3は中の各々についての候補数
  }

  rep(i, N) {
    //list4は候補数の累積和
    list4[N - i - 1] += list4[N - i]+list3[N - i - 1];
  }
  ll ans = 0;
  rep(i, N) {
    auto it = upper_bound(all(list1), list0[i]);
    int index = it - list1.begin();
    ans += list4[index];
  }
  cout << ans;
}