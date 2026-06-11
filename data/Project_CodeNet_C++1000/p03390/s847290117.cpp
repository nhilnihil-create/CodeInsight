#include <cstdio>
#include <math.h>

using namespace std;

long long ans(long long a, long long b) {
  if (a == b) {
    return 2*b-2;
  } else {
    double n2 = a*b*1.0;
    double n = sqrt(n2);
    //printf("%lf\n", n);
    long long N = (long long int)n;
    //printf("%d\n", N);
    if (n2 == N*N) {
      return 2*N-3;
    } else {
      if (N*(N+1) >= a*b) {
	return 2*N-2;
      } else {
	return 2*N-1;
      }
    }
  }
}

    

int main() {
  int q;
  int i;
  long long a[100], b[100];
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%lld %lld", &a[i], &b[i]);
  }
  for (i = 0; i < q; i++) {
    printf("%lld\n", ans(a[i], b[i]));
  }
  return 0;
}
  
    