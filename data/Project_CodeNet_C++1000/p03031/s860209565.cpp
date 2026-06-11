#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n,m;
  cin >> n >> m;
  vector<int> k(m);
  vector<int> p(m);
  vector<vector<int>> s(m,vector<int>(n));
  rep(i,m){
    int a;
    cin >> a;
    k[i] = a;
    rep(j,a){
      cin >> s[i][j];
    }
  }
  rep(i,m){
    cin >> p[i];
  }
  ll ans = 0;
  for(int bit = 0; bit < (1<<n); ++bit){
    bool have = true;
    rep(i,m){
      int sum = 0;
      rep(j,k[i]){
        if (bit & (1<<(s[i][j]-1))) {
              sum++;
            }
      }
      if(sum % 2 != p[i]){
        have = false;
      }
    }
    if(have){
      ans++;
    }
    }
  cout << ans;
  
  return 0;
}


