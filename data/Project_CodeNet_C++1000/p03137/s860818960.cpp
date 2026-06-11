#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> vec(m);
  rep(i, m) cin >> vec[i];
  sort(all(vec));
  vector<int> dis(m-1);
  rep(i, m-1) dis[i] = vec[i+1]-vec[i];
  sort(all(dis));
  if(n >= m) cout << 0 << endl;
  else{
   	ll ans = 0;
    rep(i, m-n) ans += dis[i];
    cout << ans << endl;
  }
  return 0;
}