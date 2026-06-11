#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll; 
int main() {
  ll a, b;cin>>a>>b;
  ll cnt=0;
  
  rep(i, 2) {
    if(a>=b) {
      cnt+=a;
      a--;
    }
    else {
      cnt+=b;
      b--;
    }
  }
  cout << cnt;
}
    