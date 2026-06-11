#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int g(ll x) {
  int d = 0;
    while(x>0){
    d++;
    x /= 10;
  }
    return d;
}

int top(ll x){
  while(x>=10){
    x /= 10;
  }
  return x;
}

int main(){
  ll n;
  cin >> n;

  ll m = n;
  int d = g(n);
  bool flag = 1;
  rep(i,d-1) {
    if(m%10 != 9) flag = 0;
    m /= 10;
  }

  int ans;
  if(flag) ans = top(n)+9*(d-1);
  else{
    ans = top(n)-1+9*(d-1);
  }
  cout << ans  << endl;
}
