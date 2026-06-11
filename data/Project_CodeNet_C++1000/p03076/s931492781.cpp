#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    vector<int> v(5);
    rep (i, 5)
        cin >> v[i];

    int ans = 644;
    do
    {
        int sum = 0;
        rep (i, 4)
        {
            if (v[i] % 10)
                sum += (v[i] + 10) - (v[i] % 10);
            else
                sum += v[i];
        }
        ans = min(sum + v[4], ans);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}