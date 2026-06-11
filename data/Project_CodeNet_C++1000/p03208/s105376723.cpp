#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    int N, K;
    cin >> N >> K;
    ll h[N];
    REP(i, N) cin >> h[i];

    sort(h, h + N);

    ll m = h[K - 1] - h[0];

    FOR(i, K, N) {
        ll t = h[i] - h[i - (K - 1)];
        if (t < m) m = t;
    }

    cout << m << endl;

    return 0;
}
