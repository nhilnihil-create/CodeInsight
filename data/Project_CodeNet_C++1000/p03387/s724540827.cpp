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

int main(){
  vl in(3);
  rep(i, 3) cin >> in[i];

  stable_sort(in.begin(), in.end());

  ll ans = 0;

  if((in[1] - in[0]) % 2 == 1){
    in[0]++;
    in[2]++;
    ans++;
  }

  ans += (in[1] - in[0]) / 2;
  ans += in[2] - in[1];

  cout << ans << endl;
  
  return 0;
}
