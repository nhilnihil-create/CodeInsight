#include <iostream>
using namespace std;
const long long N=200200;
const long long p=1e9+7;
  
long long a[N],n,b[N],f[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      f[i] = f[i - 1];
    } else {
      f[i] = (f[i - 1] + b[a[i]]) % p;
      b[a[i]] = f[i];
    }
  }
  cout << f[n] << endl;
}