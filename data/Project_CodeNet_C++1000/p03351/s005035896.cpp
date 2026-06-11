#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    string ans = "No";
    if (abs(a - c) <= d) ans = "Yes";
    else if (abs(a - b) <= d && abs(b - c) <= d) ans = "Yes";
    cout << ans << endl;
    return 0;
}