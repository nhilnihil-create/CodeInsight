#include<bits/stdc++.h> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vv = vector<vector<int>>;
using P = pair<int,int>;


int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if( a == b ){
    cout << c << endl; 
    return 0;
  }
  if( a == c ){
    cout << b << endl;
    return 0;
  }
  if( b == c ){
    cout << a << endl;
    return 0;
  }
  return 0;
}
