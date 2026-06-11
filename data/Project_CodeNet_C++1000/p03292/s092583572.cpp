#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    vector<int> a(3);
    rep(i, 3) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = abs(a[1] - a[0]) + abs(a[1]- a[2]);

    cout << ans << endl;



    return 0;
}