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
    vector<ll> t(N), d(N);
    priority_queue<pair<ll, ll>> q; 
    REP(i, N)
    {
        cin >> t[i] >> d[i];
        t[i]--;
        q.push(make_pair(d[i], t[i]));
    }
    ll score = 0;
    ll kind = 0;
    vector<bool> isEat(N, false);
    priority_queue<ll, vector<ll>, greater<ll>> depliQ;
    REP(i, K)
    {
        pair<ll, ll> p = q.top();
        q.pop();
        ll t = p.second;
        ll d = p.first;
        if (!isEat[t])
        {
            kind++;
            isEat[t] = true;
        }
        else
        {
            depliQ.push(d);
        }
        score += d;
    }
    score += kind * kind;

    ll ans = score;
    while (!q.empty())
    {
        pair<ll, ll> p = q.top();
        q.pop();
        ll t = p.second;
        ll d = p.first;
        if (!isEat[t])
        {
            kind++;
            isEat[t] = true;
            if (!depliQ.empty())
            {
                ll removeD = depliQ.top();
                depliQ.pop();
                score -= removeD;
                score -= (kind - 1) * (kind - 1);
                score += d;
                score += kind * kind;
                ans = max(ans, score);
            }
        }
    }

    cout << ans << endl;
}
