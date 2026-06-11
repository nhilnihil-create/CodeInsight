#include <bits/stdc++.h>
using namespace std;
double f(double x, int *v, int *l, int *r, int N) {
  double V = INT_MAX;
  for (int i = 0; i < N; i++) {
    if (x < l[i]) {
      V = min(V,v[i]+l[i]-x);
    } else if (x <= r[i]) {
      V = min(V,1.0*v[i]);
    } else {
      V = min(V,v[i]+x-r[i]);
    }
  }
  return V;
}
int main() {
  int N;
  cin >> N;
  int t[N+1];
  t[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> t[i];
    t[i] += t[i-1];
  }
  N += 2;
  int v[N], l[N], r[N];
  double distance = 0;
  v[0] = 0;
  v[N-1] = 0;
  l[0] = 0;
  r[0] = 0;
  l[N-1] = t[N-2];
  r[N-1] = t[N-2];
  for (int i = 1; i < N-1; i++) {
    l[i] = t[i-1];
    r[i] = t[i];
    cin >> v[i];
  }
  for (double x = 0.5; x <= t[N-2]; x += 0.5) {
    distance += 0.25*(f(x,v,l,r,N)+f(x-0.5,v,l,r,N));
  }
  cout.precision(20);
  cout << fixed << distance;
}