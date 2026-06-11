#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >> N;
  int pre = -1;
  long long ans = 1;
  map<int, long long> mp;
  for(int i = 0; i < N; ++i){
    int x; cin >> x;
    if(x == pre)continue;
    pre = x;
    mp[x] += ans % 1000000007;
    ans = mp[x] % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
