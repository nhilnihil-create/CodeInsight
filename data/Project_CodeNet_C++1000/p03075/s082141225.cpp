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
    int a[5], k;
    REP(i, 5) cin >> a[i];
    cin >> k;
    if (a[4] - a[0] > k) cout << ":(" << endl;
    else cout << "Yay!" << endl;
    return 0;
}
