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
    int D;
    cin >> D;
    switch (D) {
        case 22:
            cout << "Christmas Eve Eve Eve" << endl;
            break;
        case 23:
            cout << "Christmas Eve Eve" << endl;
            break;
        case 24:
            cout << "Christmas Eve" << endl;
            break;
        case 25:
            cout << "Christmas" << endl;
            break;
    }

    return 0;
}
