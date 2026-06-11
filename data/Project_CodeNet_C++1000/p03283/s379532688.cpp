#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  int n, m, Q;
  cin >> n >> m >> Q;
  int sta[500][500];
  rep(i, m){
    int l, r;
    cin >> l >> r;
    l--;r--;
    sta[l][r]++;
  }
  ll S[500][500];
  rep(i, n) S[i][i] = sta[i][i];
  for(int i = 0; i < n; i++){
    for(int j = i; j < n-1; j++){
      S[i][j+1] = S[i][j] + sta[i][j+1];
    }
  }
  
  rep(i, Q){
    int p, q;
    cin >> p >> q;
    p--;q--;
    ll res = 0;
    for(int j = p; j <= q; j++){
      res += S[j][q];
    }
    cout << res <<endl;
  }
}