#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n, a[MAXN], aSorted[MAXN];
int aBits[MAXN], aBitsSp[MAXN], af[MAXN], aib[MAXN], ord[MAXN];

int queryAib(int pos) {
    int ans = 0;
    while (pos > 0) {
        ans += aib[pos];
        pos -= (pos & (-pos));
    }

    return ans;
}

int updateAib(int pos, int val) {
    while (pos < MAXN) {
        aib[pos] += val;
        pos += (pos & (-pos));
    }
}

long long countLowerEqual(int val) {
    ord[0] = 0;
    for (int i = 1; i <= n; ++i) {
        aBits[i] = ((a[i] <= val) ? 0 : 1);
        aBitsSp[i] = aBitsSp[i - 1] + aBits[i];
        af[i] = 2 * aBitsSp[i] - i;
        ord[i] = i;
    }

    sort(ord, ord + n + 1, [&](int x, int y) {
        return af[x] > af[y];
    });
    memset(aib, 0, sizeof(aib));
    
    long long ans = 0;
    for (int i = 0; i <= n; ) {
        int j;
        for (j = i; j <= n && af[ord[j]] == af[ord[i]]; ++j);

        for (int k = i; k < j; ++k)
            ans += queryAib(ord[k]);
        for (int k = i; k < j; ++k)
            updateAib(ord[k] + 1, 1);
        i = j;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        aSorted[i] = a[i];
    }
    sort(aSorted + 1, aSorted + n + 1);

    const long long target = 1LL * n * (n + 1) / 4 + 1;
    int left = 1, right = n, mid, sol;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (countLowerEqual(aSorted[mid]) >= target) {
            sol = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << aSorted[sol] << "\n";

    return 0;
}