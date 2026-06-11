#include<bits/stdc++.h>

int main() {
  int a, b, v;
  scanf("%d %d", &a, &b);
  v = (a * b) % 2;
  if (v == 0) {
	printf("Even");
  } else {
    printf("Odd");
  }
  return 0;
}