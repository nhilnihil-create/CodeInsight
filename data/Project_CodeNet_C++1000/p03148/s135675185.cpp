#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    int N, K;
    cin >> N >> K;
    int t[N];
    ll d[N];
    vector<pair<ll, ll>> sushiVec;
    REP(i, N)
    {
        cin >> t[i] >> d[i];
        t[i]--;
        sushiVec.push_back(make_pair(d[i], t[i]));
    }

    sort(sushiVec.begin(), sushiVec.end());
    reverse(sushiVec.begin(), sushiVec.end());

    ll f[N + 1] = {0};
    ll score = 0;
    int countSushiKind = 0;
    map<int, bool> usedSushiMap;
    priority_queue<ll, vector<ll>, greater<ll>> avalableSushiQueue;
    REP(i, N) usedSushiMap[i] = false;
    REP(i, K)
    {
        ll currentD = sushiVec[i].first;
        int currentT = sushiVec[i].second;
        if (!usedSushiMap[currentT])
        {
            countSushiKind++;
            usedSushiMap[currentT] = true;
        }
        else 
        {
            avalableSushiQueue.push(currentD);
        }
        score += currentD;
    }
    f[countSushiKind] = score;

    for (int i = K; i < N; ++i)
    {
        ll currentD = sushiVec[i].first;
        int currentT = sushiVec[i].second;
        if (avalableSushiQueue.empty()) break;
        if (usedSushiMap[currentT]) continue;
        f[countSushiKind + 1] = f[countSushiKind] - avalableSushiQueue.top() + currentD;
        countSushiKind++;
        avalableSushiQueue.pop();
        usedSushiMap[currentT] = true;
    }

    ll ans = 0;
    for (ll i = 0; i <= N; ++i) if (f[i] != 0) ans = max(ans, f[i] + i * i);
    cout << ans << endl;
}
