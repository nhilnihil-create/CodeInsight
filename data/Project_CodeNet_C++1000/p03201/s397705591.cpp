#include <iostream>
#include <algorithm>
#include <map>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, a[200003], ans, p;
    ll bi[35] = {};
    map<int, int> m;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[a[i]]++;
    }

    sort(a, a + n, greater<int>());

    bi[0] = 1;
    i = 0;
    while (bi[i] < 1e9) {
        bi[i + 1] = bi[i++] * 2;
    }

    ans = 0;
    for (i = 0; i < n; i++) {
        if (m[a[i]] == 0) {
            continue;
        }
        m[a[i]]--;
        p = lower_bound(bi, bi + 31, a[i] + 1) - bi;
        if (m[bi[p] - a[i]] > 0) {
            ans++;
            m[bi[p] - a[i]]--;
        }
    }

    printf("%d\n", ans);

    return 0;
}