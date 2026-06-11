#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    int res = 0;
    rep(i, N)
    {
        if (x >= a[i])
        {
            x -= a[i];
            if (i == N - 1 && x > 0)
                break;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}