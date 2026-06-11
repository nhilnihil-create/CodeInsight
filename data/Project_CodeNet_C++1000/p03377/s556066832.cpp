#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a <= c && c <= a + b){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
  return 0;
}