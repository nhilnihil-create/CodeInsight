#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <bitset>
#include <iterator>
#define loop(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define debug(x)  cout << #x << " = " << (x) << endl;

using namespace std;
using LL = long long int;
using ULL = unsigned long long;

int main() {
    LL n, k; cin >> n >> k;
    LL ans = 0;
    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }
    for (LL b = 1; b <= n; b++)  {
        ans += max(0LL, b - k) * (n / b) + max(0LL, n % b - k + 1);
    }
    cout << ans << endl;
}
