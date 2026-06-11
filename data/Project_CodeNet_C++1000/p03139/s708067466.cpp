#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(a, b) << " " << (a + b <= n ? 0 : a + b - n) << endl;
    // end

    return 0;
}
