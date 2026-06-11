#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  string s;
  int sum = 700;
  cin >> s;
  for (int i = 0; i < 3; i++){
    if (s[i] == 'o'){
      sum += 100;
    }
  }
  cout << sum << '\n';
  return 0;
}