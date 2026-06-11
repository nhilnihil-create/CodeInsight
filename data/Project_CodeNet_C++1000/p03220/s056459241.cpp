#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n, t, a;
    cin >> n >> t >> a;

    vector<pair<int, int>> diff(n);
    rep (i, n)
    {
        int h;
        cin >> h;
        diff[i].first = abs(a * 1000 - (t * 1000 - h * 6));
        diff[i].second = i + 1;
    }

    sort(diff.begin(), diff.end());
    cout << diff[0].second << endl;
    return 0;
}
