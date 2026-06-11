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
    int N, K;
    string S;
    cin >> N >> K >> S;

    int c[N + 2];
    REP(i, N + 2) c[i] = 0;
    int itr = 0;
    bool f = (S[0] == '0')? true : false;
    if (f) {
        c[0] = 0;
        itr++;
    }
    c[itr]++;
    FOR(i, 1, N) {
        if (S[i] == S[i - 1]) {
            c[itr]++;
        }
        else {
            itr++;
            c[itr]++;
        }
    }
    itr++;
    if (S[N - 1] == '0') {
        c[itr] = 0;
        itr++;
    }

    int sum = c[0];
    for (int i = 0; i < K; ++i) {
        if (i * 2 + 1 < itr) sum += c[i * 2 + 1];
        if (i * 2 + 2 < itr) sum += c[i * 2 + 2];
    }
    int maxSum = sum;

    int start = 2 * K + 1;
    int rstart = 0;
    for (int i = start; i < itr; i += 2, rstart += 2) {
        sum -= c[rstart];
        sum -= c[rstart + 1];
        sum += c[i];
        sum += c[i + 1];
        if (sum > maxSum) maxSum = sum;
    }

    cout << maxSum << endl;
    return 0;
}
