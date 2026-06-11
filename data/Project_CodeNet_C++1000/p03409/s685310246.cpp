#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int, int>> r(n), b(n);
    
    REP(i, n) cin >> r[i].second >> r[i].first;
    REP(i, n) cin >> b[i].first >> b[i].second;
    sort(r.begin(), r.end(), greater<pair<int,int>>());
    sort(b.begin(), b.end());

    int ans = 0;
    REP(i, n) {
        REP(j, r.size()) {
            if(r[j].second < b[i].first && r[j].first < b[i].second) {
                ans++;
                r.erase(r.begin() + j);
                break;
            }
        }
    }
    cout << ans << endl;



    return 0;
}