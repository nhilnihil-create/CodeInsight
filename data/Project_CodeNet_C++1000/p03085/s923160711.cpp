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
    char b;
    cin >> b;
    if (b == 'A') cout << 'T' << endl;
    else if (b == 'C') cout << 'G' << endl;
    else if (b == 'G') cout << 'C' << endl;
    else cout << 'A' << endl;
    return 0;
}
