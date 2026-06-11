#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int a, b;
  cin >> a >> b;
  int num = b - a;
  int height = 0;
  for(int i = 1; i < num+1; ++i ){
    height += i;
  }
  int ans = height-b; 
  cout << ans << endl;
  return 0;
}