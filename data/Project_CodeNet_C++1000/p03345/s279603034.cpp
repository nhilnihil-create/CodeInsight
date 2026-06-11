#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  ll a,b,c;
  ll k;
  std::cin >> a >> b >> c >> k;

  ll ab = a-b;
  std::cout << (k%2 == 0 ? ab : -ab) << '\n';
  return 0;
}
