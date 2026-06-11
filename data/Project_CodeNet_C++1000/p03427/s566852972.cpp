#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  ll n;
  std::cin >> n;

  int ans = 0;

  while(1) {
    if(n < 10) {
      ans += n;
      break;
    }
    else {
      if(n%10 < 9) {
        ans += 9;
        n/=10;
        --n;
      }
      else {
        ans += 9;
        n/=10;
      }
    }
  }

  std::cout << ans << '\n';
  return 0;
}
