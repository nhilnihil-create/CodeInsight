#include <bits/stdc++.h>
#define f(i, a, b) for(int i=a; i < (b); ++i)
#define rep(i,n) f(i, 0, n)
using namespace std;

int main(void){
  int x, num, ans=1;
  cin >> x;
  for(int i=2; i<x; ++i){
    num = i*i;
    while(num<=x){
      ans = max(ans, num);
      num *= i;
    }
  }
  cout << ans << endl;
  return 0;
}