/**
*    created: 23.05.2020 13:00:54
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int s;
    cin >> s;
    int m = 1;
    map<int,int> mp;
    mp[s]++;
    while(true) {
        m++;
        if (s % 2 == 0) s /= 2;
        else s = 3 * s + 1;
        if (mp[s]) break;
        else mp[s]++;
    }
    cout << m << endl;
    return 0;
}
