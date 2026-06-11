#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    repl(i, 1, n + 1) {
        int v = i / 10000;
        int w = (i - (i / 10000) * 10000 ) / 1000;
        int x = (i - (i / 1000) * 1000) / 100;
        int y = (i - (i / 100) * 100) / 10;
        int z = i % 10;
        int sum = v + w + x + y + z;
        if(sum >= a && sum <= b) ans += i;
    }
    cout << ans << endl;
    return 0;
}