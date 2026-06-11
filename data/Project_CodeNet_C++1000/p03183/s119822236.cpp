#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
struct node {
    int w, s, v;
} wp[1009];
int n;
ll dp[20009], ans;

bool cmp(node a, node b) {
    return a.s + a.w < b.s + b.w;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &wp[i].w, &wp[i].s, &wp[i].v);
    }
    sort(wp + 1, wp + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 20000; j >= wp[i].w; j--) {
            if (wp[i].s + wp[i].w >= j)dp[j] = max(dp[j - wp[i].w] + 1ll * wp[i].v, dp[j]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 20000; i++)ans = max(ans, dp[i]);
    printf("%lld\n", ans);
    return 0;
}