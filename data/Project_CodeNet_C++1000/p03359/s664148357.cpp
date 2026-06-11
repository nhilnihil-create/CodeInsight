#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int a,b;
  cin >> a >> b;
  if (a <= b){
    cout << a << '\n';
  }
  else{
    cout << a-1 << '\n';
  }
  
  return 0;
}