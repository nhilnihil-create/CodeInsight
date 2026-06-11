#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define fi first
#define se second
#define inf (INT_MAX/2-1)
#define infl (1LL<<60)
#define vi vector<int>
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) begin(a),end(a)
#define y0 y5656
#define y1 y7878
#define aaa system("pause");
#define dbg(x) cerr<<(#x)<<": "<<(x)<<'\n',aaa
#define dbga(x,n) cerr<<(#x)<<"[]: ";for(int _=0;_<n;_++)cerr<<x[_]<<' ';cerr<<'\n',aaa
#define dbgs(x) cerr<<(#x)<<"[stl]: ";for(int _:x)cerr<<_<<' ';cerr<<'\n',aaa
#define dbgp(x) cerr<<(#x)<<": "<<x.fi<<' '<<x.se<<'\n',aaa
#define maxn 3000

using namespace std;

string v;
int d[maxn+5][maxn+5];///d[i][j]=nr de permutari de lg i care se termina in j
int s[maxn+5][maxn+5];///s[i][j]=s[i][1]+s[i][2]+..+s[i][j]
const int mod = 1000000007;

int main () {
  int n; cin >> n >> v; v = " " + v;
  int i, j, z;
  d[1][1] = 1;
  for (j = 1; j <= n; j++) s[1][j] = (s[1][j-1] + d[1][j]) % mod;
  for (i = 2; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      if (v[i-1] == '>') d[i][j] = (s[i-1][i-1] - s[i-1][j-1] + mod) % mod;
      else d[i][j] = s[i-1][j-1];
    }
    for (j = 1; j <= n; j++) s[i][j] = (s[i][j-1] + d[i][j]) % mod;
  }
  cout << s[n][n];
  return 0;
}
