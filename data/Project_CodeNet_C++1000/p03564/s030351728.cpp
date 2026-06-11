#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n, k;
  cin >> n >> k;
  int c = 0;
  int d = 1;
  while(c < n) {
    if (d * 2 < d + k) {
      d *= 2;
    } else {
      d += k;
    }
    c++;
  }
  cout << d << endl;
}
