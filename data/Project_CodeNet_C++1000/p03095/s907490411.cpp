#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  string s;
  cin>>N>>s;
  vector<int> cnt(30);
  for(int i(0);i<N;i++){
    cnt[s[i]-'a']++;
  }
  ll ans(1);
  for(int i(0);i<30;i++){
    ans *= (cnt[i]+1);
    ans %= MOD;
  }
  cout << ans-1 << endl;
  return 0;
}
