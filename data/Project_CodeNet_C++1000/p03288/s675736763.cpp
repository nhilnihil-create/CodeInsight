#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int r;
  cin >> r;
  if (r < 1200){
    cout << "ABC\n";
    return 0;
  }
  if ( r >= 1200 && r < 2800){
    cout << "ARC\n";
    return 0;
  }
  cout << "AGC\n";
  return 0;
}