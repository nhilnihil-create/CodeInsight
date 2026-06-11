#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N)
    {
        cin >> A[i];
    }

    vector<ll> sumA(N);
    map<ll, ll> sumModMap;
    sumA[0] = A[0];
    sumModMap[sumA[0] % M] = 1;
    REP(i, N - 1)
    {
        sumA[i + 1] = sumA[i] + A[i + 1];
        ll sumMod = sumA[i + 1] % M;
        auto it = sumModMap.find(sumMod);
        if (it != sumModMap.end())
        {
            sumModMap[sumA[i + 1] % M]++;
        }
        else
        {
            sumModMap[sumA[i + 1] % M] = 1;
        }
        
    }
    ll ans = 0;
    REP(i, N)
    {
        ll sumMod = sumA[i] % M;
        if (sumMod == 0)
        {
            ans += sumModMap[sumMod];
        }
        else
        {
            ans += max(0ll, sumModMap[sumMod] - 1);
        }
        sumModMap[sumMod]--;
    }

    cout << ans << endl;
}
