#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll n, a, b, c;
vector<ll> l;

ll dfs(ll i, ll la, ll lb, ll lc){
  if(i == n){
      if(min(la, min(lb, lc)) == 0) return 1e18;
      else return abs(a-la) + abs(b-lb) + abs(c-lc) - 30; // 30 is come from first merge.
  }
  ll ret0 = dfs(i+1, la, lb, lc); // l_i is not used for any tree.
  ll ret1 = dfs(i+1, la+l[i], lb, lc) + 10; // l_i is merged to A.
  ll ret2 = dfs(i+1, la, lb+l[i], lc) + 10; 
  ll ret3 = dfs(i+1, la, lb, lc+l[i]) + 10;
  return min(min(ret0, ret1), min(ret2, ret3));
}

int main(){
  cin >> n >> a >> b >> c;
  l.resize(n);
  rep(i, 0, n) cin >> l[i];
  
  cout << dfs(0, 0, 0, 0) << endl;
  return 0;
}
