#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll N;

void dfs(ll mult, ll val, bool th, bool fi, bool sev, ll &ans){
  if(val > N)
    return;

  if(th && fi && sev) ans++;

  dfs(10*mult, val + 3*mult, true || th, false || fi, false || sev, ans);
  dfs(10*mult, val + 5*mult, false || th, true || fi, false || sev, ans);
  dfs(10*mult, val + 7*mult, false || th, false || fi, true || sev, ans);

  return;
}

int main(){
  cin >> N;

  ll ans = 0;

  dfs(1, 0, false, false, false, ans);

  cout << ans << "\n";
  
  return 0;
}
