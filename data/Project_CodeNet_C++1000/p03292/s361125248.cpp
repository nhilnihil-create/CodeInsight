#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);
  cout << max({A,B,C})-min({A,B,C}) << endl;
}