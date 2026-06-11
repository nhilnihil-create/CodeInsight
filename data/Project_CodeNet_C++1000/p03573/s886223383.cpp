#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define chmin(x, y) x = min(x, y)
typedef long long ll;
const int INF = 1001001001;
const int mod = 1000000007;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b)
    {
        cout << c << endl;
    }
    else if (a == c)
    {
        cout << b << endl;
    }
    else
    {
        cout << a << endl;
    }
}