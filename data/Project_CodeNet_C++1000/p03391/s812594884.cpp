#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  int a[n], b[n];

  ll sum, res;
  sum = 0;
  res = 1e10;
  for(int i = 0;i < n;i++){
    cin >> a[i] >> b[i];
    sum += a[i];
    if(a[i] > b[i]){
      res = min(1LL * b[i], res);
    }
  }
  if(res == 1e10)
    cout << 0;
  else
    cout << sum - res;
  return 0;
}
