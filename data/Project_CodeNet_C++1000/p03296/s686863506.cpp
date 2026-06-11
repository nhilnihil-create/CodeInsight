#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ALL(a) (a).begin(), (a).end()
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
const ll mod = 1e9 + 7;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n - 1)
    {
        if (a[i] == a[i + 1])
        {
            ans++;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}