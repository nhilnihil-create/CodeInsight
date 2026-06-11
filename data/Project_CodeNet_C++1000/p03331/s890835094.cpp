#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  int ans = 1e5;
  rep(i,n){
    int j = n - i;
    auto sum = [](int k){
      int sum = 0;
      while (k != 0){
        sum += k % 10;
        k /= 10;
      }
      return sum;
    };
    int now = sum(i) + sum(j);
    if (now < ans) ans = now;
  }
  cout << ans << endl;
  return 0;
}