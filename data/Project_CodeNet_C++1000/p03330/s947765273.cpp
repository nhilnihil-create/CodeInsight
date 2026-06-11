#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

vector<vector<int>> d, c;
vector<vector<int>> conv;

int n, C;
ll calc(void) {
  ll res = INF;
  rep(i, C) rep(j, C) if(i != j) rep(k, C) if(i != k && j != k) {
    ll discomfort = 0;
    rep(l, C) discomfort += d[l][i] * conv[0][l];
    rep(l, C) discomfort += d[l][j] * conv[1][l];
    rep(l, C) discomfort += d[l][k] * conv[2][l];
    res = min(res, discomfort);
  }
  return res;
}

int main(){
  
  cin >> n >> C;
  d.resize(C, vector<int>(C));
  c.resize(n, vector<int>(n));
  conv.resize(3, vector<int>(C));
  rep(i, C)rep(j, C) {
    int a;
    cin >> a;
    d[i][j] = a; 
  }
  rep(i, n)rep(j, n) {
    int a;
    cin >> a;
    --a;
    c[i][j] = a;
  }
  rep(i, n) {
    rep(j, n) {
      int remainder = (i + j + 2) % 3;
      conv[remainder][c[i][j]]++;
    }
  }
  ll ans = 0;
  ans += calc();
  cout << ans << endl;


}