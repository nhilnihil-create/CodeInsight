#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  double r,g;
  cin >> r >> g;
  for (double i = -10000; i < 10000; i++){
    if ((r + i) / 2 == g){
      cout << i << '\n';
    }
  }
  return 0;
}