
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
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= n; j++){
      if (4 * i + 7 * j == n){
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}