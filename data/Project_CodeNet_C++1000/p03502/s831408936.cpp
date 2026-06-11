#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin >> n;
  int t = n;
  int r = 0;
  while(t > 0) {
    r += t % 10;
    t /= 10;
  }
  if (n % r == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
