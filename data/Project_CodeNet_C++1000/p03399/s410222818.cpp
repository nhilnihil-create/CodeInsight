#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int a[2],b[2];
  for (int i = 0; i < 2; i++){
    cin >> a[i];
  }
  for (int i = 0; i < 2; i++){
    cin >> b[i];
  }
  sort (a,a+2);
  sort (b,b+2);
  cout << a[0] + b[0] << '\n';
  
  return 0;
}