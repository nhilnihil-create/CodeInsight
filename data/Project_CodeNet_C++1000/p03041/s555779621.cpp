#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
using namespace std;

char S[60];

int main() {
  int N=0, K=0;
  scanf("%d%d", &N, &K);
  scanf("%s", S);
  S[K-1] += 32;
  cout << S << endl;
}