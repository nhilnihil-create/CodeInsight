#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (ll)n; ++i)
#define repr(i, n) for (int i = n - 1; i >= 0; --i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    int n, h, w;
    cin >> n >> h >> w;
    cout << (n - h + 1) * (n - w + 1) << endl;
}

int main(void)
{
    solve();
}