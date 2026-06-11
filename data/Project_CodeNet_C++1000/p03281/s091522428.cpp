
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
  int n,cnt = 0,cnt1 = 0;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cnt = 0;
    for (int j = 1; j <= i; j++){
      if (i % j == 0 && i % 2 == 1){
        cnt++;
      }
    }
    if (cnt == 8){
      cnt1++;
    }
  }
  cout << cnt1 << '\n';
  return 0;
}