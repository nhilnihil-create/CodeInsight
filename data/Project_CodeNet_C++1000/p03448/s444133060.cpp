#include <bits/stdc++.h>
using namespace std;
int a[3] = {500,100,50};
int ans;
int main() {
    int b,c,d,x;
    cin >> b >> c >> d >> x;
    for (int i = 0; i <= b; i++) {
      for (int j = 0; j <= c; j++) {
        for (int k = 0; k <= d; k++) {
          if (i * a[0] + j * a[1] + k * a[2] == x) {
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
    return 0;
}