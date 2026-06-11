#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll z = 0;
    cin >> n;
    int a[n + 1], b[n + 1], c[n + 1];
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    for (int i = 0 ; i < n ; i++) cin >> b[i];
    for (int i = 0 ; i < n ; i++) cin >> c[i];
    a[n] = b[n] = c[n] = 1000000007;
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    for (int i = 0; i < n; i++) z += 1ll * (lower_bound(a, a + n + 1, b[i]) - a) * (n - (upper_bound(c, c + n + 1, b[i]) - c));
    cout << z;
}