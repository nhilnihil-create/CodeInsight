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
    //freopen("B.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, t, cnt1 = 0, cnt2 = 0;
    scanf("%d %d %d", &n, &m, &x);
    n += 1;
    vi nvi(n, 0);
    rep(i, 0, m)
    {
        scanf("%d", &t);
        nvi[t] = 1;
    }
    rep(i, 0, x)
    {
        cnt1 += nvi[i];
    }
    rep(i, x, n)
    {
        cnt2 += nvi[i];
    }
    printf("%d",min(cnt1,cnt2));
    return 0;
}