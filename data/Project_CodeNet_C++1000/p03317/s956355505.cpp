#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, K;
  cin >> N >> K;
  int i = 1;
  int ans = 0;
  while(true){
    ans++;
    i += K-1;
    if(i >= N){
      cout << ans <<endl;
      return 0;
    }
  }
}