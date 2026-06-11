#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, M;
  cin >> N >> M;
  vector<pair<long long, long long>> store(N);
  for(long long i = 0; i < N; i++) {
    cin >> store[i].first >> store[i].second;
  }

  sort(store.begin(), store.end());

  long long ans = 0, cnt = 0;
  for(long long i = 0; i < N; i++) {
    if(M - cnt <= store[i].second) {
      ans += store[i].first * (M - cnt);
      cnt += M - cnt;
    }
    else {
      ans += store[i].first * store[i].second;
      cnt += store[i].second;
    }
    // cout << ans << ": " << cnt << endl;
    if(cnt == M) {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
