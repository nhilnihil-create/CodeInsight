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
  for (int i = 0; i < 3; i++){
    if (a * b * i % 2 == 1){
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}