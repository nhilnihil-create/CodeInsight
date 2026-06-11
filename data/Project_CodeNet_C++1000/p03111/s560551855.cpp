#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int reach[3];
long ans = 1e16;
void dfs(int n, int i, vi &l, vvi &pos){
  if(i == n){
    long cost = 0;
    rep(j,3){
      if(reach[j] < pos.at(j).size() || pos.at(j).size() == 0) return;
      cost += (pos.at(j).size() - 1)*10;
      long sum = 0;
      for(long x : pos.at(j)){
        sum += x;
      }
      cost += abs(reach[j] - sum);
    }
    ans = min(ans, cost);
    return;
  }
  rep(j,4){
    pos.at(j).push_back(l.at(i));
    dfs(n,i+1,l,pos);
    pos.at(j).pop_back();
  }
}

int main(){
  int n;
  cin >> n;
  rep(i,3) cin >> reach[i];
  vi l(n);
  vvi pos(4);
  rep(i,n) cin >> l.at(i);
  dfs(n,0,l,pos);
  cout << ans << endl;
}