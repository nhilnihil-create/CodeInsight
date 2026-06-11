#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
vector<int> adjlist[200000];
ii furthestnode(int v, int p) {
    ii ans = ii(v, 0);
    for (int i: adjlist[v]) {
        if (i == p) continue;
        ii k = furthestnode(i, v);
        if (k.second + 1 > ans.second) ans = ii(k.first, k.second + 1);
    }
    return ans;
}
int main() {
    int N, a, b;
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        scanf("%d %d", &a, &b);
        adjlist[a - 1].push_back(b - 1);
        adjlist[b - 1].push_back(a - 1);
    }
    int diam = furthestnode(furthestnode(0, -1).first, -1).second + 1;
    if (diam % 3 == 2) printf("Second");
    else printf("First");
    return 0;
}