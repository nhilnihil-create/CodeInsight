#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N)
    {
        cin >> A[i];
    }
    const ll maxDigit = 50;
    vector<ll> one(maxDigit, 0), zero(maxDigit, 0);
    REP(i, N)
    {
        REP(j, maxDigit)
        {
            ll num = A[i];
            if ((num >> j) & 1)
            {
                one[j]++;
            }
            else
            {
                zero[j]++;
            }
        }
    }

    ll X = 0;
    ll exp = 1;
    ll ans = 0;
    REP(i, maxDigit - 1)
    {
        exp *= 2;
    }
    for (ll i = maxDigit - 1; i >= 0; --i)
    {
        if (X + exp <= K)
        {
            if (one[i] >= zero[i])
            {
                ans += exp * one[i];
            }
            else
            {
                ans += exp * zero[i];
                X += exp;
            }
        }
        else
        {
            ans += exp * one[i];
        }
        
        exp /= 2;
    }

    cout << ans << endl;
}
