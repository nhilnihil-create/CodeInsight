#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int a[100];
int cells[100][100]; // r * c

int main() {
  int N; cin >> N;

  vector<vector<char>> S(N, vector<char>(N));

  rep0(i, N) {
    string s; cin >> s;
    rep0(j, N) {
      S[i][j] = s[j];
    }
  }

  ll ans = 0;
  rep(X, -(N-1), N) {
    bool check = true;
    rep0(i, N) {
      if (!check) break;
      rep0(j, N) {
        if ((i - j - X) % N == 0) continue;
        if (S[i][j] != S[(j + X + N) % N][(i - X + N) % N]) {
          check = false;
        }
        if (!check) break;
      }
    }
    if (check) {
      ans += (N - abs(X));
    }
  }

  cout << ans << BR;
  return 0;
}