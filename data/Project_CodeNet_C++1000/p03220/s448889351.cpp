#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, t, a;
    cin >> n >> t >> a;
    vector<int> h(n);
    rep(i, 0, n)
    {
        int tmp;
        cin >> tmp;
        h[i] = abs(1000 * a - 1000 * t + 6 * tmp);
    }
    cout << distance(h.begin(), MN(h)) + 1 << endl;
}
