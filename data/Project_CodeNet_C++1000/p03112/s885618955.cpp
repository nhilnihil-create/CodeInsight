#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B), x(Q);
    REP(i, A)
    {
        cin >> s[i];
    }
    REP(i, B)
    {
        cin >> t[i];
    }
    REP(i, Q)
    {
        cin >> x[i];
    }
    
    REP(i, Q)
    {
        vector<ll> indexS, indexT;

        auto itS = lower_bound(ALL(s), x[i]);
        if (itS == s.end())
        {
            indexS.push_back(A - 1);
        }
        else if (itS == s.begin())
        {
            indexS.push_back(0);
        }
        else
        {
            ll dist = distance(s.begin(), itS);
            indexS.push_back(dist);
            indexS.push_back(dist - 1);
        }

        auto itT = lower_bound(ALL(t), x[i]);
        if (itT == t.end())
        {
            indexT.push_back(B - 1);
        }
        else if (itT == t.begin())
        {
            indexT.push_back(0);
        }
        else
        {
            ll dist = distance(t.begin(), itT);
            indexT.push_back(dist);
            indexT.push_back(dist - 1);
        }

        ll ans = LONG_MAX;
        REP(j ,2)
        {
            REP(k, indexS.size())
            {
                REP(l, indexT.size())
                {
                    if (j == 0)
                    {
                        ans = min(ans, abs(x[i] - s[indexS[k]]) + abs(s[indexS[k]] - t[indexT[l]]));
                    }
                    else
                    {
                        ans = min(ans, abs(x[i] - t[indexT[l]]) + abs(t[indexT[l]] - s[indexS[k]]));
                    }
                }
            }
        }
        cout << ans << endl;
    }

}
