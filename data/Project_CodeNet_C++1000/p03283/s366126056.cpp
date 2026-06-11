#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int> > train(n + 1, vector<int>(n + 1, 0));
  rep(i, m) {
    int l, r;
    cin >> l >> r;
    train[l][r]++;
  }

  vector<vector<int> > cum(n + 1, vector<int>(n + 1, 0));
  for(int i = 1; i <= n; i++) cum[i][i] = train[i][i];

  for(int i = 1; i <= n - 1; i++) {
    for(int j = 1; j <= n - i; j++) {
      cum[j][j + i] = train[j][j + i] + cum[j + 1][j + i] + cum[j][j + i - 1] - cum[j + 1][j + i - 1];
    }
  }

  rep(i, q) {
    int p, q;
    cin >> p >> q;
    cout << cum[p][q] << endl;
  }
  return 0;		 
}