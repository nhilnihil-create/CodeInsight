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

    S.replace(4, 1, "");
    S.replace(6, 1, "");
    int n = stoi(S);
    if (n <= 20190430) cout << "Heisei" << endl;
    else cout << "TBD" << endl;

    return 0;
}
