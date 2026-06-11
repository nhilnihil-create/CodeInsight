#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int a,b,c[3];
  cin >> a >> b;
  c[0] = a + b;
  c[1] = a - b;
  c[2] = a * b;
  sort (c,c+3,greater<int>());
  cout << c[0] << '\n';
  return 0;
}