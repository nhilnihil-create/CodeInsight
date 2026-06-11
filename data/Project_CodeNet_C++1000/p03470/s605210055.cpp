#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i, N) cin >> d[i];
    sort(d.begin(), d.end());
    int res = 0;
    rep(i, N)
    {
        if (i == 0)
        {
            res++;
            continue;
        }
        if (d[i] - d[i - 1] != 0)
            res++;
    }
    cout << res << endl;
    return 0;
}