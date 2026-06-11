#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
//~ using ll = long long;
//~ using P = pair<int, int>;

int main(){
  int n;
  int cnt=0;
  cin >> n;
  for (int i=1; i<=n; i+=2) {
    int num=i;
    int div=0;
    for (int j=1; j<=n; j++) {
      if (num%j==0) div++;
      if (div>8) break;
    }
    if (div==8) cnt++;
  }
  cout << cnt << endl;
  
  return 0;
}
