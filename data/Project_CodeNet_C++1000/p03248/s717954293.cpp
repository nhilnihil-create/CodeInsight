#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    s = string("0") + s;

    irep(i, n)
    {
        if (s[i] != s[n - i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (s[n] == '1' || s[1] == '0') {
        cout << -1 << endl;
        return 0;
    }

    int root = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            cout << root << " " << i + 1 << endl;
        } else {
            cout << i + 1 << " " << root << endl;
            root = i + 1;
        }
    }
    return 0;
}