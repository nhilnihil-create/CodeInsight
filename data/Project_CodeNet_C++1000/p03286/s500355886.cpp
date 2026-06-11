#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  string b = "";
  cin >> n;
  int e = 0;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  while(n != 0) {
    char i = '0';
    if (n%2 != 0) {
      n -= 1;
      i = '1';
    }
    b = i + b;
    n /= -2;
    e++;
  }
  cout << b << endl;
  return 0;
}