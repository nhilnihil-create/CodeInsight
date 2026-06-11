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

int main(void)
{
    vector<int> v(3);
    rep(i, 0, 3) cin >> v[i];
    sort(all(v), greater<int>());
    cout << 10 * v[0] + v[1] + v[2] << endl;
}