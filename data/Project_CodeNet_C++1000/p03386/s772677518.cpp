#include<bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, k;
  cin >> a >> b >> k;
  long long k2 = a+k;
  k2 = min(b+1, k2);
  for(long long i=a; i<k2; i++) {
    cout << a << endl;
    a++;
  }
  long long b2 = b-k+1;
  b2 = max(a, b2);
  for(long long i=b2; i<=b; i++) {
    cout << b2 << endl;
    b2++;
  }
}