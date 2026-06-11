#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a;
  cin >> a;
  int i = 1;
  int ans = 0;
  while(i*i<=a) {
    int x = i;
    for(int j=1; ; j++) {
      if(j!=1) x *= i; 
      if(x<=a && ans<x) ans = x;
      if(x==1) break;
      if(x>a) break;
    }
    i++;
  }
  cout << ans << endl;
}