#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

const int MOD = (int) 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    rep(i, n) {
        int a;
        cin >> a;
        sum += a - 1;
    }
    cout << sum << endl;
    return 0;
}
