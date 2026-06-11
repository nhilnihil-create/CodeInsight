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
    vector<ll> x(N), y(N), z(N);
    REP(i, N)
    {
        cin >> x[i] >> y[i] >> z[i];
    }

    ll ans = 0;
    for (int i = 0; i <= 7; ++i)
    {
        ll signX, signY, signZ;
        signX = (i >> 0) & 1 ? -1 : 1;
        signY = (i >> 1) & 1 ? -1 : 1;
        signZ = (i >> 2) & 1 ? -1 : 1;
        vector<ll> sumV(N);
        REP(i, N)
        {
            ll sumE = signX * x[i] + signY * y[i] + signZ * z[i];
            sumV[i] = sumE;
        }
        sort(ALL(sumV));
        reverse(ALL(sumV));
        ll sumCake = 0;
        REP(i, M)
        {
            sumCake += sumV[i];
        }
        ans = max(ans, sumCake);
    }
    

    cout << ans << endl;
}
