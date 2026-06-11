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
    int s;
    cin >> s;

    set<int> a;
    a.insert(s);
    int prev = s;
    int itr = 1;
    while (true) {
        itr++;
        int next;
        if (prev % 2 == 0) {
            next = prev / 2;
        }
        else {
            next = 3 * prev + 1;
        }
        if (a.find(next) != a.end()) {
            break;
        }
        else {
            a.insert(next);
            prev = next;
        }
    }
    cout << itr << endl;

    return 0;
}
