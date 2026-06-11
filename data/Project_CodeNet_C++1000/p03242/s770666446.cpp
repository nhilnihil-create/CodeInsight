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
  for (int i = 0; i < 3; i++){
    if (s[i] == '1'){
      s[i] = '9';
    }
    else if (s[i] == '9'){
      s[i] = '1';
    }
  }
  cout << s << '\n';
  return 0;
}