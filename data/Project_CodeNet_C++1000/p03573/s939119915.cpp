#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b)
        cout << c << endl;
    else if (a == c)
        cout << b << endl;
    else
        cout << a << endl;
}