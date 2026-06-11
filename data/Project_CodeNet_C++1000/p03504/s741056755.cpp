#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << endl;
#define CFYN(n) cout << ( (n) ? "YES":"NO") << endl;
#define out(n) cout << (n) << endl;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

int main(void)
{
    IOS
    int n, ch;
    cin >> n >> ch;
    vector<vector<pii>> p(ch);
    REP(i,n) {
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        p[c].push_back({s,t});
    }
    REP(i,ch) sort(ALL(p[i]));
    vector<deque<pii>> p2(ch);
    priority_queue<pii,vector<pii>, greater<pii>> standby;
    priority_queue<int,vector<int>, greater<int>> record;
    REP(i,ch) {
        REP(j,p[i].size()) {
            if (j != 0 && p2[i].back().second == p[i][j].first) {
                p2[i].back().second = p[i][j].second;
            } else p2[i].push_back(p[i][j]);
        }
        if (p2[i].size() != 0) standby.push({p[i][0].first,i});
    }

    size_t ans = 0;
    while(!standby.empty()) {
        //cerr << standby.top().first << endl;
        if (record.empty() || standby.top().first <= record.top()) {
            //cerr << "s" << endl;
            pii pi = standby.top(); standby.pop();
            record.push(p2[pi.second][0].second);
            p2[pi.second].pop_front();
            if (p2[pi.second].size() != 0) standby.push({p2[pi.second][0].first,pi.second});
            //cerr << standby.top().first << endl;
        } else {
            //cerr << "r" << endl;
            record.pop();
        }
        ans = max(ans,record.size());
    }

    cout << ans << endl;

    return 0;
}