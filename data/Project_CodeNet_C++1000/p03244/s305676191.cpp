#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void)
{
    int n,ans;
    vector<pair<int, int>> a1(100001), a2(100001);

    cin >> n;
    for (int i=1;i<=n;++i) {
        int m;
        cin >> m;
        if (i % 2 == 1) {
            ++a1[m].first;
            a1[m].second = m;
        }
        else {
            ++a2[m].first;
            a2[m].second = m;
        }
    }
    sort(a1.begin(), a1.end(), greater<pair<int,int>>());
    sort(a2.begin(), a2.end(), greater<pair<int, int>>());
    ans = n / 2 - max(a1[0].first, a2[0].first);
    if (a1[0].second != a2[0].second) {
        ans += n / 2 - min(a1[0].first, a2[0].first);
    }
    else {
        ans += n / 2 - max(a1[1].first, a2[1].first);
    }

    cout << ans << endl;

    return 0;
}