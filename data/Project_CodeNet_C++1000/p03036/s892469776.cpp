#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  ll r,d,x;
  cin >> r >> d >> x;
  rep(i,10) {
    x = r*x-d;
    printf("%lld\n",x);
  }
  return 0;
}
