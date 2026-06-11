#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10, 0)), p(n, vector<int>(11));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 10; j++){
      cin >> f[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 10; j++){
      cin >> p[i][j];
    }
  }
  ll ans = -1001001001001;
  for(int bit = 1; bit < (1 << 10); bit++) {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
      int c = 0;
      for(int j = 0; j < 10; j++){
        if((bit >> j) & 1 && f[i][j]) {
          c++;
        }
      }
      sum += p[i][c];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;

  return 0;
}