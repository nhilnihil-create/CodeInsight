#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    int tmp, cnt;
    rep2(i, 1, n + 1)
    {
        cnt = 0;
        tmp = i;
        while (tmp)
        {
            cnt += tmp % 10;
            tmp /= 10;
        }
        if (a <= cnt && cnt <= b)
        {
            ans += i;
        }
    }

    cout << ans << endl;
    return (0);
}
