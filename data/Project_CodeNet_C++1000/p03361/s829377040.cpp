#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;

#define rep(i, a, b) for (int i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

const long long MOD = 1e9 + 7;
const ll num[4] = {-1, 0, 1, 0};

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> vec(h);
    rep(i, 0, h) cin >> vec[i];
    int ans = true;
    rep(i, 0, h)
    {
        rep(j, 0, w)
        {
            if (vec[i][j] == '#')
            {
                bool flag = true;
                rep(k, 0, 4)
                {

                    if (i + num[k] >= 0 && i + num[k] < h && j + num[(k + 1) % 4] >= 0 && j + num[(k + 1) % 4] < w && vec[i + num[k]][j + num[(k + 1) % 4]] == '#')
                        flag = false;
                }
                if (flag)
                    ans = false;
            }
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}