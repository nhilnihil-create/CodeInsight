#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n, t;
    cin >> n >> t;
    priority_queue<int, vector<int>, greater<int>> q;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        if (b <= t)
            q.push(a);
    }
    if (q.size() == 0)
        cout << "TLE" << endl;
    else
        cout << q.top() << endl;
}
