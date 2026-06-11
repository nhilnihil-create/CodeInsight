#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  int ans=100000000;
  cin >> N;
  
  rep(i, N) {
  	int A;
    cin >> A;
    int curr=0;
    while (A % 2 == 0) {
      curr+=1;
      A /= 2;
    }
    if (ans > curr) ans = curr;
  }
  
  cout << ans << endl;
}
