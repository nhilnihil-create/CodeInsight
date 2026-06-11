#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int f1(int n, int k) {
  int ret = 0;
  int tmp = k;
  while (n >= tmp) {
    tmp += k;
    ret++;
  }
  return ret;
}

int f2(int n, int k, int m) {
  int ret = 0;
  for(int i =1;i<=n;i++){
    if(i%k ==m) ret++;
  }
  return ret;
}



int main() {
  int n, k;
  cin >> n >> k;

  if (k % 2 == 1) {
    int v = f1(n, k);
    ll ans = (ll)v * v * v;
    cout << ans << endl;
  }else{
    int v = f2(n, k, 0);
    ll ans = (ll)v * v * v;
    v = f2(n, k, k/2);
    ans += (ll)v * v * v;
    cout << ans << endl;
  }
  return 0;
}