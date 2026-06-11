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
    int N;
    cin >> N;
    double x[N];
    string u[N];
    REP(i, N) cin >> x[i] >> u[i];

    ll sy = 0;
    double sb = 0;
    REP(i, N) {
        if (u[i] == "JPY") sy += (ll)(x[i]);
        else sb += x[i];
    }
    sb = sb * 380000 + (double)sy;
    cout << sb << endl;
    return 0;
}
