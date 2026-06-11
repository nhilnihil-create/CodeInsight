#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a < c && c < b) || (a > c && c > b) ? "Yes" : "No") << endl;
    // end

    return 0;
}
