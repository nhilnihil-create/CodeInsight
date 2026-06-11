#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    int N, A, B;
    while (~scanf("%d %d %d", &N, &A, &B)) {
          if (A + B - 1 > N || (LL)A * B < (LL)N) puts("-1");
          else {
               while (N > 0) {
                     int now = min(A, N - (B - 1));
                     for (int i = N - now + 1; i <= N; i++) printf("%d ", i);
                     N -= now;
                     B--;
               }
               puts("");
          }
          puts("");
    }
    return 0;
}
