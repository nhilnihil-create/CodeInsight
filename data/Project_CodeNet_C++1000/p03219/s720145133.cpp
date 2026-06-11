#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int x,y;
  cin >> x >> y;
  cout << x + y / 2 << '\n';
  return 0; 
}