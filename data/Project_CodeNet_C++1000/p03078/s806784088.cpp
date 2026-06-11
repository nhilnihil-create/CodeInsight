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
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    ll A[X], B[Y], C[Z];
    REP(i, X) cin >> A[i];
    REP(i, Y) cin >> B[i];
    REP(i, Z) cin >> C[i];

    // check 1 and 2
    ll sumAB[X * Y];
    int itr = 0;
    REP(i, X) {
        REP(j, Y) {
            sumAB[itr] = A[i] + B[j];
            itr++;
        }
    }
    sort(sumAB, sumAB + X * Y, greater<ll>());

    int abK = min(X * Y, K);
    ll s[abK * Z];
    itr = 0;
    REP(i, abK) {
        REP(j, Z) {
            s[itr] = sumAB[i] + C[j];
            itr++;
        }
    }
    sort(s, s + abK * Z, greater<ll>());
    REP(i, K) {
        cout << s[i] << endl;
    }

    return 0;
}
