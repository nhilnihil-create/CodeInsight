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
    vector<ll> x(N), y(N), h(N);
    vector<pair<ll, pair<ll, ll>>> infoPair(N);
    REP(i, N)
    {
        cin >> x[i] >> y[i] >> h[i];
        infoPair[i] = make_pair(h[i], make_pair(x[i], y[i]));
    }
    sort(ALL(infoPair));
    reverse(ALL(infoPair));

    const ll MAXC = 100;
    REP(cx, MAXC + 1)
    {
        REP(cy, MAXC + 1)
        {
            bool flag = true;
            pair<ll, pair<ll, ll>> ip = infoPair[0];
            ll h = ip.first;
            ll x = (ip.second).first;
            ll y = (ip.second).second;
            ll H = h + abs(x - cx) + abs(y - cy);
            REP(i, N - 1)
            {
                pair<ll, pair<ll, ll>> ipNow = infoPair[i + 1];
                ll hNow = ipNow.first;
                ll xNow = (ipNow.second).first;
                ll yNow = (ipNow.second).second;
                ll calch = max(H - abs(xNow - cx) - abs(yNow - cy), 0ll);
                if (hNow != calch)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
}
