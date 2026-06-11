#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n, x = 0, sum = 0;
  cin >> n;
  int a[n + 1];
  rep(i,n)
  {
    cin >> a[i];
    sum += abs(x - a[i]);
    x = a[i];
  }
  a[n] = 0;
  sum += abs(x);
  x = 0;
  rep(i,n)
  {
    cout << (sum - (abs(x - a[i]) + abs(a[i] - a[i + 1])) + abs(x - a[i + 1]))
        << endl;
    x = a[i];
  }
}