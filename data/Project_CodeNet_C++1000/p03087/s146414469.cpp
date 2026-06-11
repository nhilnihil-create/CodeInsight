#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll N, Q;
    string S;

    cin >> N >> Q;
    cin >> S;

    vector<ll> L(Q);
    vector<ll> R(Q);

    rep(i, Q) cin >> L.at(i) >> R.at(i);

    vector<int> dp(N);
    dp.at(0) = 0;
    rep(i, N - 1)
    {
        if (S.at(i) == 'A' && S.at(i + 1) == 'C')
        {
            dp.at(i + 1) = dp.at(i) + 1;
        }
        else
        {
            dp.at(i + 1) = dp.at(i);
        }
    }

    rep(i, Q)
    {
        cout << dp.at(R.at(i) - 1) - dp.at(L.at(i) - 1) << endl;
    }
    return 0;
}