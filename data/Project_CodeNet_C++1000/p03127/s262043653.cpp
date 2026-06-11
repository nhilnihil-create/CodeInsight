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
    int n;
    cin >> n;
    int ans;
    cin >> ans;
    repl(i, 1, n) {
        int a;
        cin >> a;
        ans = gcd(ans, a);
    }
    cout << ans << endl;
    return 0;
}
