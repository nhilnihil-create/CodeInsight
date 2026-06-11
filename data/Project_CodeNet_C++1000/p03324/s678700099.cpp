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
    int d, n;
    cin >> d >> n;
    int cta = 0;
    int i = 0;
    while (cta < n)
    {
        i++;
        int x = i;
        int f = 0;
        while (x % 100 == 0)
            x /= 100, f++;
        if (f == d)
            cta++;
    }
    cout << i << endl;
}
int main(void)
{
    solve();
}