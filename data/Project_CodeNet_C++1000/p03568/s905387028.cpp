#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int n;
  std::cin >> n;
  vt<int> a(n);
  rep(i,n)
    std::cin >> a[i];

  ll total = 1;
  ll odd = 1;
  rep(i,n) {
    total *= 3;
    if(a[i]%2==0)
      odd *= 2;
  }

  std::cout << total - odd << '\n';  
  return 0;
}
