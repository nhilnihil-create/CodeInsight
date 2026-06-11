# include <iostream>
# include <cstring>
# include <unordered_map>
using namespace std;
# define ll long long

unordered_map<ll, ll> cnt;

int main(){
  cnt[0] = 1;
  int n;
  cin >> n;

  ll ans = 0, cur = 0;
  for(int i=0; i<n; i++){
    ll num; cin >> num;
    cur += num;
    ans += cnt[cur];
    cnt[cur]++;
  }

  cout << ans << endl;
  return 0;
}