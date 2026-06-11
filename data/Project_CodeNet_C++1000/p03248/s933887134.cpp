#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

char s[N];
int p[N], n;

bool solve() {
  if (s[1] == '0') return 0;
  if (s[n] == '1') return 0;
  for (int i = 1; i < n; ++i)
    if (s[i] != s[n - i]) return 0;

  int l = n;
  for (int i = n - 1; i >= 1; --i) {
    p[i] = l;
    if (s[i] == '1') l = i;
  }

  return 1;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);

  if (solve()) {
    for (int i = 1; i < n; ++i) {
      printf("%d %d\n", i, p[i]);
    }
  } else {
    puts("-1");
  }
}
