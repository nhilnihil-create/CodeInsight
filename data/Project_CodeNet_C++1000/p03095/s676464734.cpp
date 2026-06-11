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

#define MOD 1000000007

int main(int argc, char **argv)
{
    int N;
    string S;
    cin >> N >> S;

    int count[26];
    REP(i, 26) count[i] = 0;
    REP(i, N) {
        count[(int)(S[i] - 'a')]++;
    }
    ll ans = 1;
    REP(i, 26) {
        ans = (ans * (count[i] + 1)) % MOD;
    }
    cout << ans - 1 << endl;
    return 0;
}
