#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


long long mid;
long long search(long long a, long long b){
  long long t = a * b;
  long long left, right;
  left = min(a, b);
  right = max(a, b);
  mid = (left + right) / 2 + 1;
  while (left != right) {
    mid = (left + right) / 2 + 1;
    if (mid * mid > t) {
      right = mid - 1;
    } else {
      left = mid;
    }
    //printf("%lld %lld %lld\n", left, mid, right);
  }
  //printf("\t%lld\n", left);
  mid = left;
  if ((t-1) / left <= left) {
    return left * 2 - 1;
  }
  return  left * 2;
}

int main(){
  int n;
  cin >> n;
  for (int nn = 0; nn < n; nn++ ) {
    long long a, b;
    cin >> a >> b;

    long long u = search(a, b);
    long long ans = u - 1;
    long long t = a * b;
    if (mid == 1) {
      cout << u - 1 << endl;
      continue;
    }
    for (int r = mid; r >= 1; r--) {
      if ((t-1) / r == (t-1) / (r-1)) ans--;
      else break;
    }
    for (int r = mid; r < max(a,b); r++) {
      if ((t-1) / r == (t-1) / (r+1)) ans--;
      else break;
    }
    cout << ans << endl;
  }
  return 0;
}
