#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 123456;
int a[MAXN];

int main() {
    int n;
    while (~scanf("%d", &n)) {
          for (int i = 0; i < n; i++) {
              scanf("%d", &a[i]);
          }
          sort(a, a + n);
          vector<int> line;
          for (int i = 0; i < n; i++) {
              int tmp = a[i];
              if (a[i] > (a[n - 1] / 2)) tmp = a[n - 1] - a[i];
              line.push_back(tmp);
          }
          sort(line.begin(), line.end());
          int cur = line[n - 1];
          for (int i = 0; i < n - 1; i++) {
              if (a[i] == (a[n - 1] - cur)) cur = a[i];
          }
          printf("%d %d\n", a[n - 1], cur);
    }
    return 0;
}
