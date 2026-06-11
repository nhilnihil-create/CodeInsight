#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  if((b - a - 1) % 2 == 1) printf("Alice");
  else printf("Borys");
}