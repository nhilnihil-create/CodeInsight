
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main () {
  int n,m,c,sum = 0,cnt = 0;
  cin >> n >> m >> c;
  vector<int> b(m);
  vector<vector<int>> a(n,vector<int>(m));
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  for (int i = 0; i < n; i++){
    sum = 0;
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
      sum += a[i][j]*b[j];
    }
    if (sum + c > 0){
      cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}