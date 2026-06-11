#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;

int main()
{
    char ref[2] = {'0', '1'};
    string S;
    cin >> S;
    ll ans = 0;

    bool zero = S[0] == '0';
    for (int i = 0; i < S.size(); ++i)
    {
        bool even = i % 2;
        if (zero)
        {
            if (S[i] != ref[even])
            {
                ++ans;
            }
        }
        else
        {
            if (S[i] != ref[!even])
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}