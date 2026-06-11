#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> R(M), L(M), p(Q), q(Q);
    map<pair<ll, ll>, ll> tMap;
    REP(i, M)
    {
        cin >> L[i] >> R[i];
        L[i]--; 
        R[i]--;
        pair<ll, ll> p = make_pair(L[i], R[i]);
        tMap[p]++;
    } 
    REP(i, Q)
    {
        cin >> p[i] >> q[i];
        p[i]--;
        q[i]--;
    }
    vector<ll> sumT[N];
    REP(i, N)
    {
        vector<ll> sumS(N);
        pair<ll, ll> p = make_pair(i, 0);
        sumS[0] = tMap.find(p) != tMap.end() ? tMap[p] : 0;
        REP(j, N - 1)
        {
            sumS[j + 1] = sumS[j];
            pair<ll, ll> q = make_pair(i, j + 1);
            sumS[j + 1] += tMap.find(q) != tMap.end() ? tMap[q] : 0;
        }
        sumT[i] = sumS;
    }
    REP(i, Q)
    {
        ll ans = 0;
        for (ll j = p[i]; j <= q[i]; ++j)
        {
            if (p[i] == 0) 
            {
                ans += sumT[j][q[i]];
            }
            else
            {
                ans += sumT[j][q[i]] - sumT[j][p[i] - 1];
            }
        }
        cout << ans << endl;
    }
}
