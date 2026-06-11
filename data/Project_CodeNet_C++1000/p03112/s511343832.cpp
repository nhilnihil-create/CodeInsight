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

lint le(VEC(lint)& array, lint pos)
{
    int lb = lower_bound(ALL(array), pos + 1) - BEGIN(array);
    return array[lb - 1];
}

lint ge(VEC(lint)& array, lint pos)
{
    return *lower_bound(ALL(array), pos);
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int A, B, Q;
    cin >> A >> B >> Q;
    VEC(lint) shrines(A), temples(B);
    READVEC(shrines);
    READVEC(temples);

    while (Q--) {
        lint X;
        cin >> X;

        lint ret = 100000000011LL;
        // only go left.
        if (temples[0] < X && shrines[0] < X) {
            lint t = le(temples, X);
            lint s = le(shrines, X);
            ret = min(ret, max(X - t, X - s));
        }

        // only go right.
        if (temples.back() > X && shrines.back() > X) {
            lint t = ge(temples, X);
            lint s = ge(shrines, X);
            ret = min(ret, max(t - X, s - X));
        }

        // go left for temple, and right for shrine.
        if (temples[0] < X && shrines.back() > X) {
            lint t = le(temples, X);
            lint s = ge(shrines, X);
            ret = min(ret, X - t + X - t + s - X);
            ret = min(ret, s - X + s - X + X - t);
        }

        // opposite of prev. strategy.
        if (temples.back() > X && shrines[0] < X) {
            lint t = ge(temples, X);
            lint s = le(shrines, X);
            ret = min(ret, t - X + t - X + X - s);
            ret = min(ret, X - s + X - s + t - X);
        }

        cout << ret << endl;
    }
    return 0;
};
