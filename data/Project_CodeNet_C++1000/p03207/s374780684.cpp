#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n, p, sum = 0, mx = 0;
  cin >> n;
  rep(i,n)
  {
    cin >> p;
    sum += p;
    mx = max(mx, p);
  }
  cout << sum - mx / 2;
}
