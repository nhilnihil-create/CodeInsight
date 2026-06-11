#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int N, K;
  
  cin >> N >> K;
 
  int res = 1;
  rep (i, N) {
      if (res * 2 < res + K)
        res *= 2;
      else
        res += K;
  }
  
  cout << res << endl;
}