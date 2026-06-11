#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b){
    cout << c;
  }
  if(c == b){
    cout << a;
  }
  if(a == c){
    cout << b;
  }
  
  return 0;
}




