#include<bits/stdc++.h>
using namespace std;
int precalc[100010];
int main() {
  for (int j = 1; j <= 100000; j ++) {int k = j, s = 0; while (k) {s += k % 10; k /= 10;} precalc[j] = s;}
  int n; cin >> n;
  int m = 2147483647;
  for (int i = 1; i < n; i ++) m = min(m, precalc[i] + precalc[n - i]);
  cout << m << endl;
}