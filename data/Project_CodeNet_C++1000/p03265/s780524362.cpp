#include <iostream>
#include <algorithm>
#include <complex>
#include <utility>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define point complex<ld>
#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;

using namespace std;
const ll INF = 1e18;
const int mod = 1e4, N = 1e5 + 5, inf = 1e9;

int main()
{
    IO
    int a, b, c, d, i, j, n, m;
    cin >> a >> b >> c >> d;
    i = c - (d - b);
    j = d + (c - a);
    n = a - (d - b);
    m = b + (c - a);
    cout << i << ' ' << j << ' ' << n << ' ' << m << '\n';
    return 0;
}