#include <cstdio>
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
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int MAXN = 87;
int dig[MAXN];

struct edge{
    int a, b, c;
    edge(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

int main() {
    int L;
    scanf("%d", &L);
    vector<edge> ans;
    int vnum, t;
    for (int i = 20; i >= 1; i--) {
        if ((1 << i) <= L) {
           vnum = i + 1;
           t = i;
           break;
        }
    }
    for (int i = 1; i < vnum; i++) {
        ans.push_back(edge(i, i + 1, 0));
        ans.push_back(edge(i, i + 1, (1 << (i - 1))));
    }
    int w = (1 << t);
    for (int i = vnum - 1; i >= 1; i--) {
        if (L & (1 << (i - 1))) {
           ans.push_back(edge(i, vnum, w));
           w += (1 << (i - 1));
        }
    }
    printf("%d %d\n", vnum, (int)ans.size());
    for (auto i : ans)
        printf("%d %d %d\n", i.a, i.b, i.c);

    return 0;
}
