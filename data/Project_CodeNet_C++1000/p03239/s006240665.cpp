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
    int N, T;
    cin >> N >> T;
    int c[N], t[N];
    REP(i, N) cin >> c[i] >> t[i];

    int m = 10000;
    REP(i, N) {
        if (t[i] <= T) m = min(m, c[i]);
    }
    if (m > 1000) cout << "TLE" << endl;
    else cout << m << endl;
    return 0;
}
