#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a <= 5)
        b = 0;
    else if (a <= 12)
        b /= 2;
    cout << b << endl;
    return 0;
}