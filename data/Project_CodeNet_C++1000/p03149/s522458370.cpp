#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
const ll mod = 1e9 + 7;

int main()
{
    vector<int> n(4);
    rep(i, 4) cin >> n[i];
    sort(ALL(n));
    if (n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}