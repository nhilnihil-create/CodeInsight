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
    int N, M;
    cin >> N >> M;

    int c[M];
    REP(i, M) c[i] = 0;
    REP(i, N) {
        int K;
        cin >> K;
        REP(i, K) {
            int A;
            cin >> A;
            c[A - 1]++;
        }
    }
    int ans = 0;
    REP(i, M) {
        if (c[i] == N) ans++;
    }
    cout << ans << endl;
    return 0;
}
