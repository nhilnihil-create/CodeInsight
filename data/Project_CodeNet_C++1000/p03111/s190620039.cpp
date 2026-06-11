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

const int _infinity = 1000000;
int A, B, C;
VEC(int) sticks;

int cost(int have, int need)
{
    if (have == 0)
        return _infinity;
    return abs(have - need);
}

int recurse(int i, int a, int b, int c)
{
    // Cost at this moment.
    int ret = cost(a, A) + cost(b, B) + cost(c, C);

    if (i == sticks.size())
    {
        return ret;
    }

    // leave out ith stick.
    ret = min(ret, recurse(i + 1, a, b, c));

    // join with one of a, b, c
    int s = sticks[i];
    ret = min(ret, (a == 0 ? 0 : 10) + recurse(i + 1, a + s, b, c));
    ret = min(ret, (b == 0 ? 0 : 10) + recurse(i + 1, a, b + s, c));
    ret = min(ret, (c == 0 ? 0 : 10) + recurse(i + 1, a, b, c + s));

    return ret;
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.

    int N;
    cin >> N >> A >> B >> C;
    sticks.resize(N);
    READVEC(sticks);
    int ret = recurse(0, 0, 0, 0);
    cout << ret << endl; 
    return 0;
};
