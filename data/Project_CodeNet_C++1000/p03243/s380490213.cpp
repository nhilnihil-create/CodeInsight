
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
  for (int i = n; i < 1112; i++){
    if (i == 111 || i == 222 || i == 333 || i == 444 || i == 555 || i == 666 || i == 777 || i == 888 || i == 999 || i == 1111){
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}