#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
double ave;
int main() {
  int n;
  int a[103];

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ave += a[i];
  }

  ave /= n;
  int mini = 0;
  for (int i = 1; i < n; i++) {
    if (abs(a[i] - ave) < abs(a[mini] - ave)) mini = i;
  }

  cout << mini << endl;
  return 0;
}