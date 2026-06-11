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
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if (a + b > c + d){
    cout << "Left\n";
  }
  if (a + b == c + d){
    cout << "Balanced\n";
  }
  if (a + b < c + d){
    cout << "Right\n";
  }
  return 0;
}