#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N + 1, 0);
    vector<ll> B(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        B[i] = B[i - 1] + A[i];
    }

    map<ll, ll> sameModMap;
    REP(i, N + 1)
    {
        ll res = B[i] % M;
        auto iter = sameModMap.find(res);
        if (iter == sameModMap.end())
        {
            sameModMap[res] = 1;
        }
        else
        {
            sameModMap[res]++;
        }
    }

    ll ans = 0;
    for(auto iter = sameModMap.begin(); iter != sameModMap.end(); ++iter)
    {
        ll num = iter->second;
        ans += num * (num - 1) / 2;
    }

    cout << ans << endl;
}
