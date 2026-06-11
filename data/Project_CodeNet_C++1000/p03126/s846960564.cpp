
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
  int n,m,c,cnt = 0;
  cin >> n >> m;
  vector<int> k(n),c1(m+1);
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++){
    cin >> k[i];
    for (int j = 0; j < k[i]; j++){
      cin >> c;
      a[i].push_back(c);
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < k[i]; j++){
      c1[a[i][j]]++;
    }
  }
  for (int i = 1; i <= m; i++){
    if (c1[i] == n){
      cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}