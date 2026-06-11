#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    ll K;

    cin >> S;
    cin >> K;

    ll days = 5000000000000000;

    char ans;
    rep(i, S.size())
    {
        char c = S.at(i);
        int num = (int)(c - '0');
        ll digit = days * log10(num);
        if (log10(K) <= digit)
        {
            ans = c;
            break;
        }
        else
        {
            K -= pow(num, days);
        }
    }

    cout << ans << endl;
    return 0;
}