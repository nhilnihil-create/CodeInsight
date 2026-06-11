#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n, k;
  cin >> n >> k;
  if(n < k){
    cout << "NO" << endl;
    return 0;
  }

  bool isRight = false;
  if(n % 2 == 1){
    isRight = (n + 1) / 2 >= k;
  }else{
    isRight = n / 2 >= k;
  }
  cout << ((isRight) ? "YES" : "NO") << endl;
}