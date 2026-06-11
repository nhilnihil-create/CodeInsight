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

ll X;

void dfs(vl &cnt, vl coin, ll kind, ll &pat){
  if(kind == 3){
    if(500*cnt[0] + 100*cnt[1] + 50*cnt[2] == X) pat++;
    return;
  }

  rep(i, coin[kind] + 1){
    cnt.push_back(i);
    dfs(cnt, coin, kind + 1, pat);
    cnt.pop_back();
  }
}

int main(){
  vl coin(3);
  cin >> coin[0] >> coin[1] >> coin[2] >> X;

  vl cnt;
  ll pat = 0;
  dfs(cnt, coin, 0, pat);

  cout << pat << endl;
  
  return 0;
}
