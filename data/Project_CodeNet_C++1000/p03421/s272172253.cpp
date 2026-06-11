#include <algorithm>
#include <cmath>
#include <functional>
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
    int n, a, b;
    cin >> n >> a >> b;

    if (a + b - 1 > n || n > (int64_t)a * b) {
        cout << -1 << endl;
    } else {
        vector<int> teeth(b, 0);

        teeth[0] = a;
        if (b > 1) {

            auto p = div(n - a, b - 1);
            rep(i, b - 1)
            {
                if (i < p.rem) {
                    teeth[i + 1] = p.quot + 1;
                } else {
                    teeth[i + 1] = p.quot;
                }
            }
        }

        int j = n;
        for (int l : teeth) {
            j -= l;
            rep(i, l)
            {
                cout << j + 1 + i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}