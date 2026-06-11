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
  string s;
  cin >> s;
  ll K;
  cin >> K;

  set<string> subs;

  rep(i, s.size()){
    ll max_len = min((ll)5, (ll)(s.size() - i));

    rep2(j, 1, max_len + 1) subs.insert(s.substr(i, j));
  }

  auto it = subs.begin();
  rep(i, K - 1) it++;

  cout << (*it) << endl;
  
  return 0;
}
