#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  string s,t;
  cin >> s >> t;
  if (s[0] == t[2] && s[1] == t[1] && s[2] == t[0]){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
  return 0;
}