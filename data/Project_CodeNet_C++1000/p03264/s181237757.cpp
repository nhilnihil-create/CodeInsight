#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int k;
    cin >> k;
    int d = k / 2;
    int r = k - d;
    int ans = d * r;
    cout << ans << endl;
    return 0;
}