#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  char a, b;
  cin >> a >> b;
  if(a > b){
    cout << '>';
  }
  if(a < b){
    cout << '<';
  }
  if(a == b){
    cout << '=';
  }
  return 0;
}




