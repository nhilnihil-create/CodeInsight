#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    vector<int> n(4), x{1, 4, 7, 9};
    rep(i, 4) cin >> n.at(i);
    sort(all(n));
    cout << (n == x ? "YES" : "NO") << endl;
    // end

    return 0;
}
