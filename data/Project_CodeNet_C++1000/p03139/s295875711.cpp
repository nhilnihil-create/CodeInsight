#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
  	scanf("%d %d %d", &n, &a, &b);
  	int r = min(a, b);
  	int s = max(a + b - n, 0);
  	printf("%d %d\n", r, s);
}