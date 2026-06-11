#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  vector<int> a(5);
  rep(i,5) cin >> a[i];
  int check = 10;
  int last = 0;
  int num = 6;
  rep(i,5){
    if(a[i] % 10 != 0 && a[i] % 10 < check){
      last = a[i];
      num = i;
      check = a[i] % 10;
    }
  }
  rep(i,5){
      if(i == num) continue;
      a[i] = a[i] + (10 - a[i] % 10)%10;
  }
  int ans = 0;
  rep(i,5){
    if(i == num) continue;
    ans += a[i];
  }
  ans += last;
  cout << ans << endl;
}