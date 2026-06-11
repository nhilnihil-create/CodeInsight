#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 0; i < (n) + 1; i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
using namespace std;

// ABC085C
int main()
{
    int n, y;
    cin >> n >> y;

    bool lie = true;
    rep1(i, y / 10000) {
        int y_ = y - i * 10000;
        rep1(g, y_ / 5000) {
            int y__ = y_ - g * 5000;
            int s = y__ / 1000;
            if (i + g + s == n) {
                cout << i << " " << g << " " << s << endl;
                lie = false;
            }
            if (!lie) break;
        }
        if (!lie) break;
    }

    if (lie) cout << "-1 -1 -1" << endl;

    return 0;
}