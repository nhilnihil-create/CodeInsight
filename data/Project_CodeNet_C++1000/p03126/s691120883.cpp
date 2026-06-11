#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    rep(i, n)
    {
        int k;
        cin >> k;
        rep(i, k)
        {
            int a;
            cin >> a;
            a--;
            c[a]++;
        }
    }
    int ans = 0;
    rep(i, m)
    {
        if (c[i] == n)
        {
            ans++;
        }
    }
    cout << ans << endl;
}