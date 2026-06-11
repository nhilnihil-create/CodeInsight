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

/**
 * Disjoint set data structure, uses compression by height.
 */
class DisjointSet
{
public:
    DisjointSet(int _n)
    {
        n = _n;
        root.resize(n);
        height.resize(n);
        size.resize(n);

        for (int i = 0;i < n; i++) {
            root[i] = i;
            height[i] = 0;
            size[i] = 1;
        }
    }

    int getRoot(int x)
    {
        if (root[x] == x)
            return x;

        return root[x] = getRoot(root[x]);
    }

    lint merge(int x, int y)
    {
        int rx = getRoot(x), ry = getRoot(y);
        if (rx == ry)
            return 0LL;

        lint ret = size[rx] * 1LL * size[ry];
        if (height[rx] < height[ry]) {
            root[rx] = ry;
            size[ry] += size[rx];
        } else if (height[rx] > height[ry]) {
            root[ry] = rx;
            size[rx] += size[ry];
        } else {
            root[ry] = rx;
            height[rx]++;
            size[rx] += size[ry];
        }

        return ret;
    }
private:
    int n;
    vector<int> root, height, size;
};
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
    VEC(int) A(M), B(M);
    FOR(i, 0, M) {
        cin >> A[i] >> B[i];
    }

    VEC(lint) V(M + 1);
    lint total = N * 1LL * (N - 1) / 2;
    DisjointSet dset(N);

    V[M] = total;
    FORD(i, M - 1, -1) {
        total -= dset.merge(A[i] - 1, B[i] - 1);
        V[i] = total;
    }

    FOR(i, 1, M + 1)
        cout << V[i] << endl;
    return 0;
};
