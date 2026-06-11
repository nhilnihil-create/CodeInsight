#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
  int N, x;
  cin >> N >> x;
  int a[N];
  rep(i, N) cin >> a[i];
  int cnt = 0;
  sort(a, a + N);
  rep(i, N){
    x -= a[i];
    cnt++;
    if (x < 0){
      cnt--;
      break;
    }
  }
  if (x > 0) cnt--;
    
  cout << cnt << endl;
}