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
  ll H, W;
  cin >> H >> W;
  vvc ss(H, vc(W));
  string s;
  rep(i, H){
    cin >> s;
    
    rep(j, W) ss[i][j] = s[j];
  }

  rep(i, H){
    rep(j, W){
      if(ss[i][j] == '.') continue;
      
      if((i > 0) && (ss[i - 1][j] == '#')) continue;
      if((i < H - 1) && (ss[i + 1][j] == '#')) continue;
      if((j > 0) && (ss[i][j - 1] == '#')) continue;
      if((j < W - 1) && (ss[i][j + 1] == '#')) continue;

      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  
  return 0;
}
