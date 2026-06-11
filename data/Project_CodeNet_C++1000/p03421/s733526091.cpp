#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a >= (n + b - 1) / b && a + b <= n + 1) {
        vector<int> g, sol;
        g.push_back(b);
        int res = n - b, cur_a = 1;
        while (res > 0) {
            if (res >= b && res - b >= a - cur_a - 1) {
                res -= b;
                g.push_back(b);
                cur_a++;
            } else if (a - cur_a > 1) {
                res--;
                g.push_back(1);
                cur_a++;
            } else {
                g.push_back(res);
                res = 0;
                cur_a++;
            }
        }
        int cur = 0;
        for (int i = 0; i < g.size(); i++) {
            int max = cur + g[i];
            for (int j = max; j > cur; j--) {
                sol.push_back(j);
            }
            cur = max;
        }
        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", sol[i]);
        }
        puts("");
    } else {
        puts("-1");
    }
    return 0;
}