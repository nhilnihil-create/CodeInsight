#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

int main() {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        vector<int> pos(n);
        rep(i, n) {
                int p;
                scanf("%d", &p);
                p --;
                pos[p] = i;
        }
        const long long inf = 1e18;
        vector<vector<long long>> cur(n + 1, vector<long long> (2));
        rep(i, n) {
                vector<vector<long long>> next(n + 1, vector<long long> (2));
                vector<long long> mi0(n + 1), mi1(n + 1);
                mi0[0] = cur[0][0];
                rep(j, n + 1) if (j) {
                        mi0[j] = min(mi0[j - 1], cur[j][0]);
                }
                mi1[0] = cur[0][1];
                rep(j, n + 1) if (j) {
                        mi1[j] = min(mi1[j - 1], cur[j][1]);
                }

                // rep(j, n + 1) cerr << mi0[j] << ' '; cerr << endl;
                // rep(j, n + 1) cerr << mi1[j] << ' '; cerr << endl;

                rep(j, n + 1) {
                        next[j][0] = inf;
                        next[j][1] = inf;
                        int cost = 0;
                        if (j < pos[i]) cost = b;
                        if (j > pos[i]) cost = a;
                        // hei
                        if (j != n + 1) {
                                if (j > 0) next[j][0] = min(next[j][0], mi0[j - 1] + cost);
                                if (j > 0) next[j][0] = min(next[j][0], mi1[j - 1] + cost);
                                /*
                                rep(k, j) {
                                        next[j][0] = min(next[j][0], cur[k][0] + cost);
                                        next[j][0] = min(next[j][0], cur[k][1] + cost);
                                }
                                */
                                next[j][0] = min(next[j][0], cur[j][1] + cost);
                        }
                        // kai
                        if (j == pos[i]) cost = b;
                        if (j > 0) next[j][1] = min(next[j][1], mi0[j - 1] + cost);
                        /*
                        rep(k, j) {
                                next[j][1] = min(next[j][1], cur[k][0] + cost);
                        }
                        */
                        next[j][1] = min(next[j][1], mi1[j] + cost);
                        /*
                        rep(k, j + 1) {
                                next[j][1] = min(next[j][1], cur[k][1] + cost);
                        }
                        */
                }
                // rep(j, n + 1) cerr << next[j][0] << ' '; cerr << endl;
                // rep(j, n + 1) cerr << next[j][1] << ' '; cerr << endl;
                cur.swap(next);
        }      
        long long ans = inf;
        rep(i, n + 1) {
                ans = min(ans, cur[i][0]);
                ans = min(ans, cur[i][1]);
        }
        printf("%lld\n", ans);
        return 0;
}
