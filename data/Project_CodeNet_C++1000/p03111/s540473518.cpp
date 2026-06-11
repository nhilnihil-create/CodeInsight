#include <bits/stdc++.h>
typedef long long ll;
#define _GLIBCXX_DEBUG
#define int long long
using namespace std;
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPR(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MAXIN(x) max_element(ALL(x)) - v.begin();
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PI 3.14159265358979323846
using namespace std;

int N;
int A[3];
vector<int> l;

int saiki(int i, int a, int b, int c) {
    if (i == N) {
        if (!a || !b || !c) return INF;
        return abs(a - A[0]) + abs(b - A[1]) + abs(c - A[2]);
    }
    int res = saiki(i + 1, a, b, c);
    res = min(res, saiki(i + 1, a + l[i], b, c) + (a ? 10 : 0));
    res = min(res, saiki(i + 1, a, b + l[i], c) + (b ? 10 : 0));
    res = min(res, saiki(i + 1, a, b, c + l[i]) + (c ? 10 : 0));

    return res;
}

signed main() {
    cin >> N >> A[0] >> A[1] >> A[2];
    l.resize(N);
    REP(i, N) { cin >> l[i]; }
    //  sort(ALL(l));

    cout << saiki(0, 0, 0, 0) << endl;

    // int cnt[3];
    // REP(j, 3) {
    //     if (l[0] < A[j]) {
    //         cnt[j] = -1;
    //         continue;
    //     }
    //     REP(i, N) {
    //         if (l[i] >= A[j]) {
    //             break;
    //         }
    //         cnt[j]++;
    //     }
    // }

    // int sa[3];
    // REP(i, 3) {
    //     if (cnt[i] != N || cnt[i] == -1) {
    //         if (A[i] - l[cnt[i]] >= A[i] - l[cnt[i - 1]]) {
    //             sa[i] = A[i] - l[cnt[i]];
    //         } else {
    //             sa[i] = A[i] - l[cnt[i - 1]];
    //             cnt[i]--;
    //         }
    //     }
    // }

    return 0;
}