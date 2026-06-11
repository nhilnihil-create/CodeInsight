#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> A(N);

    rep(i, N) cin >> A.at(i).first >> A.at(i).second;

    sort(A.begin(), A.end());

    ll ans = 0;
    ll m = 0;

    rep(i, N)
    {
        if (m + A.at(i).second < M)
        {
            m += A.at(i).second;
            ans += A.at(i).first * A.at(i).second;
        }
        else
        {
            ans += A.at(i).first * (M - m);
            break;
        }
    }

    cout << ans << endl;

    return 0;
}