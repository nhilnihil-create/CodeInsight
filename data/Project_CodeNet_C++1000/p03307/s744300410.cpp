#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  long long n;
  cin >> n;
  if (n % 2 ==0){
    cout << n << '\n';
  }
  else{
    cout << n * 2 << '\n';
  }
  return 0;
}