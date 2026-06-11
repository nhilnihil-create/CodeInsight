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
  cin >> s;
  if (s[5] == '0' && s[6] <= '4'){
    cout << "Heisei\n";
  }
  else{
    cout << "TBD\n";
  }
  return 0;
}