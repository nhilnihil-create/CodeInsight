#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int a[3],k;
  for (int i = 0; i < 3; i++){
    cin >> a[i];
  }
  cin >> k;
  for (int i = 0; i < k; i++){
   sort (a,a+3,greater<int>());
   a[0] *= 2 ;
  }
  cout << a[0] + a[1] + a[2] << '\n';
  return 0;
}