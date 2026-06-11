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
    int n, K;
    cin >> n >> K;
    string S;
    cin >> S;

    int ret = 0, kSpan = 0;
    VEC(int) zeros;
    FOR(i, 0, n) {
        if (S[i] == '1') {
            kSpan++;
        } else {
            if (i == 0 || S[i - 1] == '1')
                zeros.push_back(i);
            else
                zeros.back() = i;

            if (zeros.size() <= K)
                kSpan = i + 1;
            else {
                kSpan = i - zeros[zeros.size() - 1 - K];
            }
        }

        ret = max(ret, kSpan);
    }

    cout << ret << endl;
    return 0;
};
