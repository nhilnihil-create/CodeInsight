#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

void dfs(vector<int> &ta, vector<int> &l, vector<int> &p, vector<int> &co, int lv, int &ans){
  int n = l.size();
  if(lv == n){
    int add = 0;
    rep(i, 3){
      if(p.at(i) == 0) return ;
      add += abs(ta.at(i) - p.at(i));
      add += 10 * (co.at(i)-1);
    }
    ans = min(ans, add);
    return ;
  }
  dfs(ta, l, p, co, lv+1, ans);
  rep(i, 3){
    p.at(i) += l.at(lv);
    co.at(i)++;
    dfs(ta, l, p, co, lv+1, ans);
    p.at(i) -= l.at(lv);
    co.at(i)--;
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> ta(3);
  rep(i, 3) cin >> ta.at(i);
  vector<int> l(n);
  rep(i, n) cin >> l.at(i);
  vector<int> p(n, 0), co(n, 0);
  int ans = 1001001001;
  dfs(ta, l, p, co, 0, ans);
  cout << ans << endl;
  return 0;
}