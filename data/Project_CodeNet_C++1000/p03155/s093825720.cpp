#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {

  int n, h, w;
  scanf("%d%d%d", &n, &h, &w);
  printf("%d\n", (n - h + 1) * (n - w + 1));

  return 0;
}
