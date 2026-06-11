#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
#include <cmath>
#include <iomanip>
#include <numeric>
using namespace std;

#define INF 1e18
#define int long long

signed main() {
    int n, a, b; cin >> n >> a >> b;

    int x = min(a, b);
    int y = max((int)0, a + b - n);

    cout << x << " " << y << endl;
    return 0;
}
