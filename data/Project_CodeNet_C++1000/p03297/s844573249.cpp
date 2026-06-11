#include <bits/stdc++.h>
using namespace std;


long long gcd(long long a, long long b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}
bool ok(long long a, long long b, long long c, long long d) {
  if (b > d) {
    return false;
  }
  if (b > a) {
    return false;
  }
  if (c >= b) {
    return true;
  }
  long long g = gcd(b, d);
  long long tmp = a - (a + b - c - 1) / g  * g;
  if (tmp < 0 && tmp >= c + 1 - b) {
    return false;
  } else {
    return true;
  }
}
int main() {
  int T;
  cin>>T;
  for (int t=0; t<T; t++) {
    long long a, b, c, d;
    cin>>a>>b>>c>>d;
    if (ok(a, b, c, d)) {
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
  }
}