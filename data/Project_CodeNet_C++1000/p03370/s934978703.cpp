#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    rep(i, n) cin >> m[i];
    sort(m.begin(), m.end());
    int sum = 0;
    rep(i, n) sum += m[i];
    cout << n + (x - sum) / m[0] << endl;
    return 0;
}