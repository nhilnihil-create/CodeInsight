#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a,b;
  int k;
  cin>>a>>b>>k;
  rep(i,k) {
    if (i%2==0) {
      if (a%2==1)  a--;
      b += a/2;
      a/=2;
    } else {
      if (b%2==1) b--;
      a += b/2;
      b/= 2;
    }
  }
  cout<<a<<" "<<b;
}
