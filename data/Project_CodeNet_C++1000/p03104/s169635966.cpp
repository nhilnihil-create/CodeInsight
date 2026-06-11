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

ll f(ll n)
{
    ll c = n / 2 + 1;
    if (n % 2 == 0) c--;
    ll ans;
    if (c % 2 == 0) ans = 0;
    else ans = 1;
    if (n % 2 == 0) ans = ans ^ n;
    return ans;
}

int main(int argc, char **argv)
{
    ll A, B;
    cin >> A >> B;

    if (A == 0)
        cout << f(B) << endl;
    else {
        cout << (f(B) ^ f(A - 1)) << endl;
    }
    return 0;
}
