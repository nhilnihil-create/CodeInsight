#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll N;
  vector<ll> cap(6);
  cin >> N;
  cap[0] = N;
  for (int i = 1; i < 6; i++){
    cin >> cap[i];
  }

  vector<ll> cnt(6);
  cnt[0] = 1;
  for (int i = 1; i < 6; i++)
  {
    cnt[i] = (N + cap[i] - 1) / cap[i];
    //cerr << "cnt[" << i << "=" << cnt[i] << endl;
  }
  
  sort(cnt.begin(), cnt.end());
  ll sum = 5 + (cnt.back() - 1);
  
  cout << sum << endl;
  return 0;
}
