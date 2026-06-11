#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a,a+3,greater<int>());
  cout << a[0] * 10 + a[1] + a[2] << '\n';
  return 0;
}