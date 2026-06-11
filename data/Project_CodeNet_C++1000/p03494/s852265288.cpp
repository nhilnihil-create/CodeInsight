#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<n; i++)

int main() {
  int n;
  cin >> n;
  int ans = 10<<9+1;
  rep(i, n) {
    int a;
    cin >> a;
    int cnt = 0;
    while (a%2 == 0) {
      a/=2;
      cnt+=1;
    }
    if (ans > cnt) {
      ans=cnt;
    }   
  }
  cout << ans << endl;
}