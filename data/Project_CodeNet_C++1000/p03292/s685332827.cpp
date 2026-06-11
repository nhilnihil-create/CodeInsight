#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d, e, f;
    d = abs(a - b);
    e = abs(b - c);
    f = abs(c - a);
    cout << min(min(d + e, e + f), f + d) << endl;
}