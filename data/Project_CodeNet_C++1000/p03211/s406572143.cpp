#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
  int m=9999;
  string s;
  std::cin >> s;
  rep(i,s.size()-2){
    int
    n=s[i]-'0';
    n=n*10+s[i+1]-'0';
    n=n*10+s[i+2]-'0';
    // std::cout << n << '\n';
    m=min(m,abs(n-753));

  }
  std::cout << m << '\n';

  return 0;
}
