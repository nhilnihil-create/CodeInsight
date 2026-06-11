#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << max({a * 10 + b + c, a + b * 10 + c, a + b + c * 10}) << endl;
    return 0;
}