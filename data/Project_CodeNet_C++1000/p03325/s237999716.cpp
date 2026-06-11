#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  int n;
  std::cin >> n;

  std::vector<ll> a(n);
  std::vector<ll> w(n,0);

  rep(i,n){
    ll temp;
    std::cin >> temp;
    a[i]=temp;
    while (temp/2>0 && temp%2==0) {
      temp/=2;
      w[i]++;
    }
  }

  ll ans=0;
  rep(i,n)ans+=w[i];
  std::cout << ans << '\n';

  return 0;
}
