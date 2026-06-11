#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = int64_t;

int main() {
  int t;
  cin >> t;
  ll a, b, c, d;

  while (t--) {
    cin >> a >> b >> c >> d;
    // 無条件No: 初めから在庫ない、補充量がb未満、補充する前に終了

    // 次にb未満になるのに補充されない　これはどんな時？
    // cよりデカく、bより小さい数が現れるか？
    // (a + d * x) mod bを考えればよさそう
    if (a < b || d < b || c < a - a / b * b)
      cout << "No";
    else {
      if (b <= c + 1)
        cout << "Yes";
      else {
        // y = (a % b + (d % b) * x) % bがc < y < bとなるか
        // c以下ギリギリまで近づけて、超えた後にb未満ならNo
        if (d % b == 0)
          cout << "Yes";
        else {
          ll g = __gcd(b, d);
          ll x = (c - a % b) / g;
          ll y = a % b + g * x;
          cout << (y + g < b ? "No" : "Yes");
        }
      }
    }
    cout << '\n';
  }
  return 0;
}