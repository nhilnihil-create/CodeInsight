#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B), x(Q);
    REP(i, A) cin >> s[i];
    REP(i, B) cin >> t[i];
    REP(i, Q) cin >> x[i];

    REP(i, Q)
    {
        ll dist = LONG_MAX;
        auto iterS = upper_bound(s.begin(), s.end(), x[i]);
        auto iterT = upper_bound(t.begin(), t.end(), x[i]);
        vector<int> indexS, indexT;
        if (iterS == s.begin()) indexS.push_back(0);
        else if (iterS == s.end()) indexS.push_back(A - 1);
        else
        {
            int index = distance(s.begin(), iterS);
            indexS.push_back(index);
            indexS.push_back(index - 1);
        }
        if (iterT == t.begin()) indexT.push_back(0);
        else if (iterT == t.end()) indexT.push_back(B - 1);
        else
        {
            int index = distance(t.begin(), iterT);
            indexT.push_back(index);
            indexT.push_back(index - 1);
        }
        REP(j, 2)
        {
            for (auto si = indexS.begin(); si != indexS.end(); ++si)
            {
                for (auto ti = indexT.begin(); ti != indexT.end(); ++ti)
                {
                    if (j == 0) dist = min(dist, abs(x[i] - s[*si]) + abs(s[*si] - t[*ti]));
                    else dist = min(dist, abs(x[i] - t[*ti]) + abs(s[*si] - t[*ti]));
                }
            }
        }
        cout << dist << endl;
    }
}
