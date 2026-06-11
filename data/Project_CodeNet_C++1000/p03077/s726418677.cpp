#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
    ll n, a, b, c, d, e; cin >> n >> a >> b >> c >> d >> e;
    ll ans = 5 + n/min({a, b, c, d, e});
    cout << min(ans, 5 + n - 1) << endl;
}

int main()
{
    solve1();
}