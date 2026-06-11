#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, M;
    cin >> N >> M;
    VEC(int) need = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    VEC(int) good(M);
    READVEC(good);
    sort(ALL(good));
    reverse(ALL(good));

    VEC(int) dp(N + 1, -1);
    dp[0] = 0;
    FOR(i, 1, N + 1) {
        for(int g : good)
            if (need[g] <= i && dp[i - need[g]] >= 0)
                dp[i] = max(dp[i], 1 + dp[i - need[g]]);
    }

    while (N > 0) {
        int digits = dp[N];
        for(int g : good)
            if (need[g] <= N && dp[N - need[g]] >= 0 &&
                    digits == 1 + dp[N - need[g]]) {
                cout << g;
                N -= need[g];
                break;
            }
    }

    cout << endl;
    return 0;
};
