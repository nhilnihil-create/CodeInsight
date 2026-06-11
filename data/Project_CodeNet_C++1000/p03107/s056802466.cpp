#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

int main()
{
    string S;
    cin >> S;
    ll ans = 0;

    for (int i = 0; i < S.size() - 1; ++i)
    {

        if (S[i] != S[i + 1])
        {

            if (i + 1 > S.size())
            {
                break;
            }
            S.erase(i, 2);
            ++ans;
            ++ans;
            i = -1;
        }
    }
    cout << ans << endl;
}
