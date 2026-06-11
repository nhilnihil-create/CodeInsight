#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int n, k;
    cin >> n >> k;
    cout << (k * 2 - 1 <= n ? "YES" : "NO") << endl;
    // end

    return 0;
}
