#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a + b == 15)
        cout << "+" << endl;
    else if (a * b == 15)
        cout << "*" << endl;
    else
        cout << "x" << endl;
}