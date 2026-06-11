#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int n,k;
  cin >> n >> k;
  if (n % k == 0){
    cout << "0\n";
  }
  else{
    cout << "1\n";
  }
  return 0;
}