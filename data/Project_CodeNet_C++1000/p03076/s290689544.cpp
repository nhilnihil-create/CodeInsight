/**
*    created: 14.05.2020 13:51:33
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int maxtime(int n) {
    while (n % 10 != 0) n++;
    return n;
}

int remtime(int n) {
    return maxtime(n)-n;
}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int sum = maxtime(a) + maxtime(b) + maxtime(c) + maxtime(d) + maxtime(e);
    int rem = max({remtime(a), remtime(b), remtime(c), remtime(d), remtime(e)});
    cout << sum - rem << endl;
    return 0;
}