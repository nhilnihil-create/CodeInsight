#include <iostream>
#include <algorithm>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, t, s;
    const int rg[4] = { 2,3,4,6 };
    vector<int> ans;

    scanf("%d", &n);

    if (n <= 5) {
        printf("2 5 63");
        if (n >= 4) {
            printf(" 20");
        }
        if (n >= 5) {
            printf(" 30");
        }
        printf("\n");
        return 0;
    }

    t = 0;
    s = 0;
    for (i = 0; i < n; i++) {
        ans.push_back(t / 4 * 6 + rg[t % 4]);
        s += t / 4 * 6 + rg[t % 4];
        t++;
    }

    if (s % 6 == 0) {
        for (i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return 0;
    }

    if (s % 6 == 2) {
        for (i = 0; i < n; i++) {
            if (ans[i] != 8) {
                printf("%d ", ans[i]);
            }
        }
        printf("%d\n", t / 4 * 6 + 6);
        return 0;
    }

    if (s % 6 == 5) {
        for (i = 0; i < n; i++) {
            if (ans[i] != 9) {
                printf("%d ", ans[i]);
            }
        }
        printf("%d\n", t / 4 * 6 + 4);
        return 0;
    }

    if (s % 6 == 3) {
        for (i = 0; i < n; i++) {
            if (ans[i] != 9) {
                printf("%d ", ans[i]);
            }
        }
        printf("%d\n", t / 4 * 6 + 6);
        return 0;
    }

    return 0;
}