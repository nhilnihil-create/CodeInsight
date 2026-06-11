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
    int N, T, A;
    cin >> N >> T >> A;
    int H[N];
    REP(i, N) cin >> H[i];

    double m = 1000000;
    int ans = 0;
    REP(i, N) {
        double c = (double)T - (double)(H[i]) * 0.006;
        c = abs((double)A - c);
        if (c < m) {
            m = c;
            ans = i + 1;
        }
    }
    cout << ans << endl;

    return 0;
}
