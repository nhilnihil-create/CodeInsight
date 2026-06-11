#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
void solve(void)
{
    int a, b;
    cin >> a >> b;
    if (a > 8 || b > 8)
        cout << ":(" << endl;
    else
        cout << "Yay!" << endl;
}
int main(void)
{
    solve();
}