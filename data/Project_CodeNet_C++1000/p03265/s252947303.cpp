#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    int distx = x2 - x1, disty = y2 - y1;
    int x3 = x2 - disty, y3 = y2 + distx;
    int x4 = x1 - disty, y4 = y1 + distx;
    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
    return 0;
}