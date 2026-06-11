#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    vector<int> x(999);
    rep(i, 999) {
        x[i] = (i + 1) * (i + 2) / 2;
    }
    int a, b;
    cin >> a >> b;
    rep(i, 998) {
        if(b - a == x[i + 1] - x[i]) cout << x[i] - a << endl;
    }
    return 0;
}