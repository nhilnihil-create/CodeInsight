#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  vector<pair<string,int>> t(n);
  rep(i,n){
    int s;
    cin >> t[i].first >> s;
    t[i].second = 100 - s;
  }
  vector<pair<string,int>> l(n);
  l = t;
  sort(l.begin(), l.end());
  vector<int> ans(n);
  rep(i,n){
    rep(j,n){
      if(l[j] == t[i])ans[j] = i+1;
    }
  }
  rep(i,n)cout << ans[i] << endl;
}


