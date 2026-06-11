#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;

vector<string> d;

void dfs(string s, int i){
  if (i == 10) d.push_back(s);
  else{
    dfs(s+'0', i+1);
    dfs(s+'1', i+1);
  }
}

int main(){
  string ss = "";
  dfs(ss, 0);
  sort(ALL(d));
  d.erase(d.begin());

  int n;
  cin >> n;
  vector<vector<char>> f(n, vector<char>(10));
  rep(i, n) rep(j, 10) cin >> f[i][j];
  vector<vector<int>> p(n, vector<int>(11));
  rep(i, n) rep(j, 11) cin >> p[i][j];

  int ans = -INF;
  rep(i, d.size()){
    int tmp = 0;
    rep(j, n){
      int c = 0;
      rep(k, 10){
        if (d[i][k] == '1' && d[i][k] == f[j][k]) c++;
      }
      tmp += p[j][c];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}