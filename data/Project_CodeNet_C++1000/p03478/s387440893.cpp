#include <bits/stdc++.h>
using namespace std;

bool check(int p,int x,int y){
  int c = 0;
  while(p > 0){
    c += p % 10;
    p /= 10;
  }
  if(x <= c && c <= y){
    return true;
  }
  return false;
}
 
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int res = 0;
  for(int i = 1; i <= n; ++i){
    if(check(i,a,b)){
      res += i;
    }
  }
  cout << res;
}