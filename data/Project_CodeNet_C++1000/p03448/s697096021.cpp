#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for(int i = n - 1; i >= 0; i--)

int main() {
  int a,b,c,x;
  cin >> a >> b >> c >> x;

  int sum = 0;
  int count = 0;
  rep(i,(a + 1)){
    rep(j,(b + 1)){
      rep(k,(c + 1)){
        sum = 500 * i + 100 * j + 50 * k;
        if (sum == x) count++;
      }
    }
  }
  cout << count << endl;
}