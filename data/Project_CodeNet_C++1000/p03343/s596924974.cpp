#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1e9;
const int MN = 2010;
int n, k, q;
int a[MN];

int solve(int lw) {
    vector<int> all, v;
    for (int i = 0; i <= n; i++) {
        if (i == n || a[i] < lw) {
            if (int(v.size()) >= k) {
                nth_element(v.begin(), v.begin() + int(v.size()) - k + 1, v.end());
                sort(v.begin(), v.end());
                for (int j = 0; j <= int(v.size()) - k; j++) {
                    all.push_back(v[j]);
                }
            }
            v.clear();
        } else {
            v.push_back(a[i]);
        }
    }
    if (int(all.size()) < q) {
        return INF;
    }
    nth_element(all.begin(), all.begin() + q, all.end());
    return *max_element(all.begin(), all.begin() + q) - *min_element(all.begin(), all.begin() + q);
}

int main() {
    scanf("%d %d %d", &n, &k, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, solve(a[i]));
    }
    printf("%d\n", ans);
    return 0;
}