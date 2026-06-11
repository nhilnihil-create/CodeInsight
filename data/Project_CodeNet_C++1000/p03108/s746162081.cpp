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

int getroot(int x, VEC(int)& root)
{
    if (root[x] == x)
        return x;
    return root[x] = getroot(root[x], root);
}

lint merge(int x, int y, VEC(int)& root, VEC(int)& size)
{
    int rx = getroot(x, root), ry = getroot(y, root);
    if (rx == ry)
        return 0LL;

    lint ret = size[rx] * 1LL * size[ry];
    if (size[rx] > size[ry]) {
        root[ry] = rx;
        size[rx] += size[ry];
    } else {
        root[rx] = ry;
        size[ry] += size[rx];
    }

    return ret;
}

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N, M;
    cin >> N >> M;
    VEC(int) A(M), B(M);
    FOR(i, 0, M) {
        cin >> A[i] >> B[i];
    }

    VEC(lint) V(M + 1);
    lint total = N * 1LL * (N - 1) / 2;

    VEC(int) root(N), size(N);
    FOR(i, 0, N)
        root[i] = i, size[i] = 1;

    V[M] = total;
    FORD(i, M - 1, -1) {
        total -= merge(A[i] - 1, B[i] - 1, root, size);
        V[i] = total;
    }

    FOR(i, 1, M + 1)
        cout << V[i] << endl;
    return 0;
};
