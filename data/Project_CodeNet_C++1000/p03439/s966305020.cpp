#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  
  string V = "Vacant";
  string M = "Male";
  string F = "Female";
  
  string start;
  cout << 0 << endl;;
  cin >> start;
  if( start == V ) return 0;
  
  int ng = 0;
  int ok = N;
  string S;
  while( ok-ng > 1 ){
    int mid = (ok+ng)/2;
    cout << mid << endl;
    cin >> S;
    if( S == V ) return 0;
    //偶数番目なのに最初と等しいor奇数番目なのに最初と違う場合
    if( (S == start && mid%2 == 1) || (S != start && mid%2 == 0) ){
      ok = mid;
    }else ng = mid;
  }
  
}
