#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ll a[10000];
  int N, ans;
  ans = 0;
  cin >> N;
  for(int i = 0;i < N;i++) cin >> a[i];
  for(int i = 0;i < N;i++) {
    while(1){
      if((a[i] % 2) == 1 || a[i] == 0){
        break;
      } else {
        ans++;
        a[i] = a[i] / 2;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
  