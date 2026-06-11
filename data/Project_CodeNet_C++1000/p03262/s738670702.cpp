#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return(gcd(b, a % b));
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> y(n+1);
    rep(i, n) cin >> y[i];
    y[n] = x;
    sort(y.begin(), y.end());
    int t = y[1] - y[0];
    repl(i, 1, n) {
        int s = y[i + 1] - y[i];
        t = gcd(s, t);
    }
    cout << t << endl;
    return 0;
}
