#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n, k;cin>>n>>k;
  // map<int, int> a;
  int a[n+1];
  rep(i, n+1) {
    a[i] = 300000;
  }

  int type_num = 0;
  for(int i=1; i < n+1; i++){
    int tmp; cin>>tmp;
    if (a[tmp] == 300000) {
      type_num ++;
      a[tmp] = 1;
    } else {
      a[tmp] ++;
      // cout << "a[" << tmp << "]: " << a[tmp] << endl;
    }
  }

  // cout << "type_num: " << type_num << endl;
  // cout << a[0] << endl;
  // sort(begin(a), end(a));
  sort(a, a+n+1);
  // cout << a[1] << endl;

  int ans = 0;
  rep(i, type_num-k) {
    ans += a[i];
  }

  cout << ans << endl;
  return 0;
}