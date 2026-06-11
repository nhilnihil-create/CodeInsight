#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
    // freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, k;
    set<int> s;
    cin >> a >> b >> k;
    if (a + k - 1 >= b - k + 1)
    {
        rep(i, a, b + 1)
        {
            printf("%d\n", i);
        }
    }
    else
    {
        rep(i, a, a + k)
        {
            printf("%d\n", i);
        }
        rep(i, b - k + 1, b + 1)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}