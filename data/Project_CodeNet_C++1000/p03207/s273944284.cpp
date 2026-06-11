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
    int N;
    cin >> N;
    int p[N];
    REP(i, N) cin >> p[i];

    int s = 0;
    REP(i, N) s += p[i];

    int m = 0;
    REP(i, N) if (m < p[i]) m = p[i];

    cout << s - m + (m / 2) << endl;
    return 0;
}
