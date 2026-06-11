#include <cstdio>
#include <iterator>
#include <iostream>
#include <cassert>
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
typedef pair<LL, LL> pll;
const int MAXN = 234567;
set<int> col[MAXN];

int dfs(int x, int y, int tu) {
    //printf("x = %d y = %d tu = %d\n", x, y, tu);
    if (tu == 0) {
       if (col[y].find(x + 1) != col[y].end())
          return x;
       else
          return dfs(x + 1, y, 1);
    }
    int rans = (*col[y].upper_bound(x)) - 1;
    if (col[y].find(x + 1) != col[y].end())
        return x;
    else if (col[y + 1].find(x) == col[y + 1].end())
        return min(rans, dfs(x, y + 1, 0));
    else
        return dfs(x, y, 0);
}

int main() {
    int H, W, N;
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        col[Y].insert(X);
    }
    for (int i = 1; i <= W; i++) col[i].insert(H + 1);
    for (int i = 1; i<= H; i++) col[W + 1].insert(i);
    printf("%d\n", dfs(1, 1, 0));
    return 0;
}
