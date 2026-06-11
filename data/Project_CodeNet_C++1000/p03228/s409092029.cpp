#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long

int main() {
  ll a, b;
  int k;
  cin >> a >> b >> k;

  int flag = 0;
  for(int i = 0; i < k; i++) {
    //cout << a << " " << b << endl;
    if(flag == 0) {
      if(a % 2 != 0) {
        a--;
        if(a <= 0) {
          a = 0;
        }

      }
      b += a/2;
      a = a/2;
      flag = 1;
    }
    else if(flag == 1) {
      if(b % 2 != 0) {
        b--;
        if(b <= 0) {
          b = 0;
        }

      }
      a += b/2;
      b = b/2;
      flag = 0;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}
