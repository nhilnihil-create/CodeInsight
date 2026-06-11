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
    int N, K;
    cin >> N >> K;
    VEC(int) V(N);
    READVEC(V);

    int ret = 0;
    FOR(l, 0, N + 1)
        FOR(r, 0, N + 1)
            if (l + r <= min(K, N)) {
                VEC(int) taken;
                FOR(i, 0, l)
                    taken.push_back(V[i]);
                FOR(i, 0, r)
                    taken.push_back(V[N - 1 - i]);

                sort(ALL(taken));
                int best = 0, ops = K - l - r;
                for(int v : taken) {
                    if (v < 0 && ops > 0) {
                        ops--;
                    }
                    else best += v;
                }

                ret = max(ret, best);
            }

    cout << ret << endl;
    return 0;
};
