// https://atcoder.jp/contests/agc024/tasks/agc024_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long a, b, c, k;
    cin >> a >> b >> c >> k;
    int sgn = k & 1 ? 1 : -1;
    cout << (sgn * (b - a)) << endl;
    return 0;
}
