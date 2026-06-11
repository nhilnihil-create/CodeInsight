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
    string S;
    cin >> S;
    int l = S.length();
    int m = 100000;
    REP(i, l - 2) {
        int a = (int)(S[i] - '0') * 100 + (int)(S[i + 1] - '0') * 10 + (int)(S[i + 2] - '0');
        if (abs(a - 753) < m) m = abs(a - 753);
    }
    cout << m << endl;

    return 0;
}
