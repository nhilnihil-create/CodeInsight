#include <algorithm>
#include <iostream>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main()
{

    int n;
    cin >> n;

    int64_t m = 2 * 1e14;
    int64_t s = 0;
    rep(i, n)
    {
        int64_t a, b;
        cin >> a >> b;
        s += a;
        if (a > b) {
            m = min(m, b);
        }
    }
    int64_t result = s - min(m, s);
    cout << result << endl;

    return 0;
}