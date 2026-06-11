#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

ll digit(ll n) {
    ll res = 0;
    while(n != 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    int ans = INF;
    for (int i = 1; i <= n / 2; ++i) {
        int cnt = digit(i) + digit(n - i);
        ans = min(ans, cnt);
    }

    cout << ans << "\n";

    return 0;
}
