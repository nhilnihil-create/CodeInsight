#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
          if (a * b == 15) puts("*");
          else if (a + b == 15) puts("+");
          else puts("x");
    }
    return 0;
}
