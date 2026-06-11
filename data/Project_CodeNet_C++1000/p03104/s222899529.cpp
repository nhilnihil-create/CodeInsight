#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void solve(){
  long long a, b, ans = 0; cin >> a >> b;
  if(a != 0) a--;
  for(long long i = 2; i <= b * 2; i *= 2){
    if(i == 2){
      long long c, d;
      if(a % 2 == 0) c = a / 2;
      else c = a / 2 + 1;
      if(b % 2 == 0) d = b / 2;
      else d = b / 2 + 1;
      if((d - c) % 2 == 1) ans++;
      continue;
    }
    long long x = a % i, y = b % i;
    //cout << x << " " << y << endl;
    if(x < i / 2){
      if(y >= i / 2 && y % 2 == 0) ans += i / 2;
    }
    else if(x % 2 == 0){
      if(y < i / 2 || y % 2 == 1) ans += i / 2;
    }
    else{
      if(y >= i / 2 && y % 2 == 0) ans += i / 2;
    }
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
