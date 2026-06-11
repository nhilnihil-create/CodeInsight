#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N, 0);
    REP(i, N) cin >> A[i];

    map<ll, ll> sumMap;
    vector<ll> sumA(N, 0);
    sumA[0] = A[0];
    sumMap[sumA[0]]++;
    REP(i, N - 1)
    {
        sumA[i + 1] = sumA[i] + A[i + 1];
        sumMap[sumA[i + 1]]++;
    }
    ll ans = 0;
    REPV(iter, sumMap)
    {
        if (iter->first == 0) ans += iter->second;
        ans += iter->second * (iter->second - 1) / 2;
    }

    cout << ans << endl;
}
